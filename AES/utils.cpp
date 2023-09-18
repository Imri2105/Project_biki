#include "boxes.hpp"
#include <iostream>

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
/*
void subBytes(unsigned char state[][4])
{
    for (int i=0;i<16;i++)
    {
        state[i] = sBox[state[i]];
    }
}
*/

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



void mixColumn(unsigned char state[][4])
{

}

int main()
{
    unsigned char init_state[4][4] = {{0x01,0x02,0x03,0x04},{0x05,0x06,0x07,0x08},{0x09,0xA,0xB,0xC},{0xD,0xE,0xF,0x10}};
    shiftRow(init_state);
    printState(init_state);
    return 0;
}