#include "boxes.hpp"
#include <iostream>

void printState(int state[][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            std::cout<<state[i][j]<<' ';
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

void shiftRow(int state[][4])
{
    int tmp;
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
void mixColumn(int state[][4])
{

}

int main()
{
    int init_state[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    shiftRow(init_state);
    printState(init_state);
    return 0;
}