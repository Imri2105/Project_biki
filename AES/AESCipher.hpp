#ifndef AES_CIPHER_HPP
#define AES_CIPHER_HPP

#include "AesFunctions.hpp"
#include "Utils.hpp"
#include "AesKeyExpand.hpp"
class AESCipher{
private:
    AESFunctions tools = AESFunctions();
    AESKeyExpand key_tools = AESKeyExpand();
public:
    AESCipher();
    ~AESCipher();
    std::vector<unsigned char> Encrypt(std::string data, std::vector<unsigned char> key);
    std::vector<unsigned char> Encrypt(std::vector<unsigned char> data, std::vector<unsigned char> key);
    std::vector<unsigned char> Decrypt(std::vector<unsigned char> cipher_text, std::vector<unsigned char> key);
    
};

#endif