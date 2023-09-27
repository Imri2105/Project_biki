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

void AESFunctions::UnPad(std::vector<unsigned char>& data){
    data.resize(data.size()-data.back());
}




