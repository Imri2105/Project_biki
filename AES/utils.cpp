#include "pch.hpp"
#include "Utils.hpp"

void PrintArray(unsigned char arr[],int size){
    for(int i = 0;i<size;i++){
        std::cout<<std::hex<<(int)arr[i]<<' ';
    }
    std::cout<<std::endl;

}

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
