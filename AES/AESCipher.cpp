#include "AESCipher.hpp"
#include "pch.hpp"

AESCipher::AESCipher(){
    //this->tools = AESFunctions();
}
AESCipher::~AESCipher(){

}

std::vector<unsigned char> AESCipher::Encrypt(std::vector<unsigned char> data, std::vector<unsigned char> key){
    this->tools.Padding(data);
    std::vector<matrix> blocks = DivideToMatrix(data);
    matrix key_matrix = DivideToMatrix(key).at(0);
    matrix copy_key_matrix = key_matrix;
    for(size_t i = 0;i<blocks.size();i++){
        key_matrix = copy_key_matrix;
        this->tools.AddRoundKey(blocks[i],key_matrix);
        for(int round = 1;round<=10;round++){
            this->key_tools.ExpandKey(key_matrix,round);
            this->tools.Round(blocks[i],key_matrix,round);
        }

    }

    return FlatMatrixes(blocks);
}

std::vector<unsigned char>AESCipher::Decrypt(std::vector<unsigned char> cipher_text, std::vector<unsigned char> key){

    this->tools.UnPad(cipher_text);
    return std::vector<unsigned char>();
}