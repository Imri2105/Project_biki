#include "pch.hpp"
#include "Utils.hpp"
#include "boxes.hpp"

void PrintArray(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout<<std::hex<<(int)arr[i]<<' ';
    }
    std::cout<<std::endl;

}

void RotateOnce(unsigned char arr[], int size){
    unsigned char temp = arr[0];
    for(int i=1; i < size; i++){
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;
}

void PrintState(unsigned char state[][4]){
    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 4; j++)
        {
            std::cout<<std::hex<<(int)state[i][j]<<' ';
        }
        std::cout<<"\n";
    }
}

void CopyMatrix(unsigned char des[][4],unsigned char src[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            des[i][j] = src[i][j];
        }
    }
}

unsigned char SubByte(unsigned char byte){
    return sBox[byte/16][byte%16];
}

unsigned char GetRcon(int index){
    return Rcon[index];
}