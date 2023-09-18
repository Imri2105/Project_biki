#include "AesFunctions.hpp"
#include "pch.hpp"
#include "boxes.hpp"

AESFunctions::AESFunctions(){
    std::cout << "IM ALIVE" << std::endl;
}

AESFunctions::~AESFunctions(){
    std::cout << "IM NOT ALIVE" << std::endl;
}

void AESFunctions::SubBytes(unsigned char state[][4]){
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            state[i][j] = sBox[state[i][j]/16][state[i][j]%16];
        }
    }
}

void AESFunctions::ShiftRow(unsigned char state[][4]){
    unsigned char tmp = 0x00; //starting value
    for (int i=1;i<4;i++) // loop over row
    {
        for (int j=0;j<i;j++) // how many times shift left
        {
            tmp = state[i][0];
            for (int k=0;k<3;k++)
                state[i][k] = state[i][k+1];
            state[i][3] = tmp;
        }
    }
}

unsigned char AESFunctions::IfTwo(unsigned char to_mul){
    //calculates the num if it needs to be multiplied by 2
    if(to_mul>=128){
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

void AESFunctions::MixColumn(unsigned char state[][4]){
    int i =0;
}