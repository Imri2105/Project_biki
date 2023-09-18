#include "AES/pch.hpp"
#include "AES/AesFunctions.hpp"
#include "AES/Utils.hpp"

int main(int argc, char const *argv[]){
    AESFunctions aes_class = AESFunctions();
    unsigned char a = 0x4C;
    unsigned char result = aes_class.CalculateNum(0x3,a);
    std::cout<<(int)result;
    return 0;
}
