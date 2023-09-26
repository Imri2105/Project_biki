#include "pch.hpp"
#include "Utils.hpp"
#include "boxes.hpp"

void PrintArray(std::vector<unsigned char> vector){
    for(int i = 0; i < vector.size(); i++){
        std::cout<<std::hex<<(int)vector[i]<<' ';
    }
    std::cout<<std::endl;

}

void PrintBlocks(std::vector<matrix> blocks){
    for(matrix block:blocks){
        PrintState(block);
        std::cout<<"\n\n";
    }
        
}

void RotateOnce(std::vector<unsigned char> &vector){
    unsigned char temp = vector[0];
    for(int i=1; i < vector.size(); i++){
        vector[i-1] =vector[i];
    }
    vector.back() = temp;
}

void PrintState(matrix state){
    for (int i=0; i < 4; i++)
    {
        for (int j=0; j < 4; j++)
        {
            std::cout<<std::hex<<(int)state[j][i]<<' ';
        }
        std::cout<<"\n";
    }
}

void CopyMatrix(matrix &des,const matrix &src){
    des = src;
}


void PrintVector(std::vector<unsigned char> v){
    for(unsigned char item: v)
        std::cout<<std::hex<<(int)item<<" ";
    std::cout<<std::endl;
}

unsigned char SubByte(unsigned char byte){
    return sBox[byte/16][byte%16];
}

unsigned char GetRcon(int index){
    return Rcon[index];
}

matrix CreateEmptyMatrix(){
    matrix m;
    m.resize(4,std::vector<unsigned char>(4,0));
    return m;
}


std::vector<matrix> DivideToMatrix(std::vector<unsigned char> data){
    std::vector<matrix> divided_vector;
    for(int i = 0;i<data.size();i+=16){
        matrix temp = CreateEmptyMatrix();
        for(int j = i;j<i+16;j++){
            int index = j%16;
            temp[index/4][index%4] = data.at(j);
        }
        divided_vector.push_back(temp);
    }
    return divided_vector;
}




