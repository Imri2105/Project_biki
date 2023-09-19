#include "pch.hpp"
#include "Utils.hpp"

void PrintState(unsigned char state[][4]){
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            std::cout<<std::hex<<(int)state[i][j]<<' ';
        }
        std::cout<<"\n";
    }
}
