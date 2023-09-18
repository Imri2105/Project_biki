#include "boxes.hpp"
#include <iostream>
#include <vector>

void printState(unsigned char state[][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            std::cout<<(int)state[i][j]<<' ';
        }
        std::cout<<"\n";
    }

}

void subBytes(unsigned char state[][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            state[i][j] = sBox[state[i][j]/16][state[i][j]%16];
        }
    }
}

void shiftRow(unsigned char state[][4])
{
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

unsigned char if_two(unsigned char to_mul){ //calculates the num if it needs to be multiplied by 2
    
    if(to_mul>=128){
        unsigned char rest = to_mul-128;     
        unsigned char temp = rest*2;
        return temp^0x1B; 
    }
    return to_mul*0x2;   
}

unsigned char calcNum(unsigned char mul, unsigned char to_mul){ //gets a two numbers to be multiplied and returns the result
    if(mul == 0x1)
        return to_mul;
    if(mul == 0x2)
        return if_two(to_mul);
    return if_two(to_mul)^to_mul;
}


void mixColumn(unsigned char state[][4])
{
    unsigned char tmp[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++)
            {
                tmp[j][i] ^= calcNum(mixMatrix[j][k],state[k][i]);
            }
        }
    }
    state = tmp;
    printState(state);
}

int main()
{   
    
    unsigned char init_state[4][4] = {{0x87,0xf2,0x4d,0x97},{0x6e,0x4c,0x90,0xec},{0x46,0xe7,0x4a,0xc3},{0xa6,0x8c,0xd8,0x95}};
    mixColumn(init_state);
    return 0;
}