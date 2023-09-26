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
    for(size_t i = 0;i<blocks.size();i++){
        tools.SubBytes(blocks[i]);
        std::cout<<"round"<<i<<std::endl;
    }
    PrintBlocks(blocks);

    return std::vector<unsigned char>();
}

std::vector<unsigned char>AESCipher::Decrypt(std::vector<unsigned char> cipher_text, std::vector<unsigned char> key){

    this->tools.UnPad(cipher_text);
    return std::vector<unsigned char>();
}