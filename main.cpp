#include "AES/pch.hpp"
#include "AES/AesFunctions.hpp"
#include "AES/Utils.hpp"
#include "AES/AesKeyExpand.hpp"
#include "AES/AESCipher.hpp"

int main(int argc, char const *argv[]){ //checks if mixColumn works, it works.
    AESCipher c;
    //std::vector<unsigned char> data = {0x87,0x6E,0x46,0xa6,0xf2,0x4c,0xe7,0x8c,0x4d,0x90,0x4a,0xd8,0x97,0xEC,0xc3,0x95};
    //std::vector<unsigned char> key = {0xac,0x77,0x66,0xf3,0x19,0xfa,0xdc,0x21,0x28,0xd1,0x29,0x41,0x57,0x5c,0x00,0x6a};
    std::vector<unsigned char> data(16,0x42);
    std::vector<unsigned char> key(16,0x41);
    std::vector<unsigned char> cipher = c.Encrypt(data,key);
    PrintVector(cipher);
        

    return 0;
}
