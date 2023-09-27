#include "AesFunctions.hpp"
#include "pch.hpp"
#include "boxes.hpp"
#include "Utils.hpp"

AESFunctions::AESFunctions(){
    std::cout << "IM ALIVE" << std::endl;
}

AESFunctions::~AESFunctions(){
    std::cout << "IM NOT ALIVE" << std::endl;
}


void AESFunctions::SubBytes(matrix &state){
    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 4; j++)
        {
            state[i][j] = SubByte(state[i][j]);
        }
    }
}

void AESFunctions::ShiftRow(matrix &state){
    unsigned char tmp = 0x00; //starting value
    for (int i=1;i<4;i++) // loop over row
    {
        for (int j=0;j<i;j++) // how many times shift left
        {
            tmp = state[0][i];
            for (int k=0;k<3;k++)
                state[k][i] = state[k+1][i];
            state[3][i] = tmp;
        }
    }
}

unsigned char AESFunctions::IfTwo(unsigned char to_mul){
    //calculates the num if it needs to be multiplied by 2
    if(to_mul >= 128){
        unsigned char rest = to_mul-128;     
        unsigned char temp = rest*2;
        return temp^0x1B; 
    }
    
    return to_mul*0x2;
        
}

unsigned char AESFunctions::CalculateNum(unsigned char mul, unsigned char to_mul){ 
    //gets a two numbers to be multiplied and returns the result
    if(mul == 0x1){
        return to_mul;
    }
    if(mul == 0x2){
        return this->IfTwo(to_mul);
    }
    return this->IfTwo(to_mul)^to_mul;
}

void AESFunctions::MixColumn(matrix &state){
    matrix tmp = CreateEmptyMatrix();
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++)
            {
                tmp[i][j] ^= CalculateNum(mixMatrix[j][k],state[i][k]);
            }
        }
    }
    CopyMatrix(state,tmp);
}

void AESFunctions::AddRoundKey(matrix &state,matrix &key){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++)
            state[i][j]^=key[i][j];
    }
}

void AESFunctions::Round(matrix &state, matrix &round_key, int round_num){
    this->SubBytes(state);
    this->ShiftRow(state);
    if (round_num != 10)
        this->MixColumn(state);
    this->AddRoundKey(state,round_key);
}

void AESFunctions::Padding(std::vector<unsigned char>& data){
    size_t pad_size = this->BLOCK_SIZE - (data.size()% this->BLOCK_SIZE);
    data.resize(data.size()+pad_size,pad_size);
}

//---------------------------------------------------end of encryption functions

void AESFunctions::UnPad(std::vector<unsigned char>& data){
    data.resize(data.size()-data.back());
}

void AESFunctions::InverseShiftRow(matrix &state){
    unsigned char tmp = 0x00; //starting value
    for (int i=1;i<4;i++) // loop over row
    {
        for (int j=0;j<i;j++) // how many times shift left
        {
            tmp = state[3][i];
            for (int k=3;k>0;k--)
                state[k][i] = state[k-1][i];
            state[0][i] = tmp;
        }
    }
}

void AESFunctions::InverseSubBytes(matrix &state){
    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 4; j++)
        {
            state[i][j] = InverseSubByte(state[i][j]);
        }
    }
}

unsigned char AESFunctions::GetMul(int value){
    if(value<degree_8)
            return (unsigned char)value;
    else if (value<degree_9)
    {
        return 0x1B^(value-degree_8);
    }

    else if(value<degree_8+degree_9){
        return 0x36^(value-degree_9);
    }
    else if(value<degree_10){
        return 0x36^0x1B^(value-768);
    }

    else if(value <degree_10+degree_8){
        return 0x6c^(value-degree_10);
    }
    
    else if(value<degree_10+degree_9){
        return 0x6c^0x1B^(value-degree_8-degree_10);
    }
    else if(value<degree_10+degree_9+degree_8){
        return 0x6c^0x36^(value-degree_9-degree_10);
    }

    return 0x6C^0x36^0x1B^(value-degree_10-degree_9-degree_8);

}

unsigned char AESFunctions::MulNum(int degree, unsigned char to_mul){
    unsigned char temp;
    switch (degree)
    {
    case 3:
    {
        int temp_int = to_mul*8;
        temp = GetMul(temp_int);
        break;
    }
    case 2:
    {
        int temp_int = to_mul*4;
        temp = GetMul(temp_int);
        break;
    }
    case 1:
    {
        int temp_int = to_mul*2;
        temp = GetMul(temp_int);
        break;
    }
    case 0:
    {
        temp = to_mul;
        break;
    }
    }
    return temp;
}

unsigned char AESFunctions::CalculateInverseNum(unsigned char mul, unsigned char to_mul){
    unsigned char temp;
    switch (mul)
    {
    case 9:
    {
        temp = MulNum(3,to_mul)^MulNum(0,to_mul);
        break;
    }
    case 0xb:
    {
        temp = MulNum(3,to_mul)^MulNum(1,to_mul)^MulNum(0,to_mul);
        break;
    }
    case 0xd:
    {
        temp = MulNum(3,to_mul)^MulNum(2,to_mul)^MulNum(0,to_mul);
        break;
    }
    case 0xe:
        temp = MulNum(3,to_mul)^MulNum(2,to_mul)^MulNum(1,to_mul);
        break;

    }
    return temp;
}

void AESFunctions::InverseMixColumn(matrix &state){
    matrix tmp = CreateEmptyMatrix();
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++)
            {   
                tmp[i][j] ^= CalculateInverseNum(inverseMixMatrix[j][k],state[i][k]);
            }
        }
    }
    CopyMatrix(state,tmp);
}

void AESFunctions::DecryptRound(matrix &state, matrix &round_key, int round_num){
    this->InverseShiftRow(state);
    this->InverseSubBytes(state);
    this->AddRoundKey(state,round_key);
    if(round_num!=10){
        this->InverseMixColumn(state);
    }
}




