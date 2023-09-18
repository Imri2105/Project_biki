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

unsigned char if_two(unsigned char to_mul){ //calculates the num if it needs to be multiplied by 2
    
    if(to_mul>=128){
        unsigned char rest = to_mul-128;     
        unsigned char temp = rest*2;
        return temp^0x1B; 
    }
    
    return to_mul*0x2;
        
}

unsigned char calculate_num(unsigned char mul, unsigned char to_mul){ //gets a two numbers to be multiplied and returns the result
    if(mul == 0x1){
        return to_mul;
    }
    if(mul == 0x2){
        return if_two(to_mul);
    }
    return if_two(to_mul)^to_mul;

    

}

void mixColumn(unsigned char state[][4])
{
    int i =0;
}

int main()
{   
    /*
    unsigned char init_state[4][4] = {{0x01,0x02,0x03,0x04},{0x05,0x06,0x07,0x08},{0x09,0xA,0xB,0xC},{0xD,0xE,0xF,0x10}};
    shiftRow(init_state);
    printState(init_state);
    */
    unsigned char a = 0x4C;
    unsigned char result = calculate_num(0x3,a);
    std::cout<<(int)result;
    return 0;
}