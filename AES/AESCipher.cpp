#include "AESCipher.hpp"
#include "pch.hpp"

AESCipher::AESCipher(){
    //currently empty
}
AESCipher::~AESCipher(){
    //currently empty
}

std::vector<unsigned char> AESCipher::Encrypt(std::vector<unsigned char> data, std::vector<unsigned char> key){
    if(key.size()!=16){
        throw std::invalid_argument("key length should be exactly 128 bits");
    }
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

std::vector<unsigned char> AESCipher::Encrypt(std::string data, std::vector<unsigned char> key){
    std::vector<unsigned char> bytes_data(data.begin(),data.end());
    return this->Encrypt(bytes_data,key);
}

std::vector<unsigned char>AESCipher::Decrypt(std::vector<unsigned char> cipher_text, std::vector<unsigned char> key){
    std::vector<matrix> blocks = DivideToMatrix(cipher_text);
    matrix key_matrix = DivideToMatrix(key).at(0);
    std::vector<matrix> keys = this->key_tools.GetRoundKeys(key_matrix,10);
    for(size_t i = 0;i<blocks.size();i++){
        this->tools.AddRoundKey(blocks[i],keys[0]);
        for(int round = 1;round<=10;round++){
            this->tools.DecryptRound(blocks[i],keys[round],round);
        }
    }
    std::vector<unsigned char> decrypted = FlatMatrixes(blocks);
    this->tools.UnPad(decrypted);
    return decrypted;
}