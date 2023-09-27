#include "AES/pch.hpp"
#include "AES/AesFunctions.hpp"
#include "AES/Utils.hpp"
#include "AES/AesKeyExpand.hpp"
#include "AES/AESCipher.hpp"

int main(int argc, char const *argv[]){ //checks if mixColumn works, it works.

    AESCipher c;
    AESFunctions f;
    std::string data = "imri is the king";
    //std::vector<unsigned char> data = {0x47,0x37,0x94,0xED,0x40,0xD4,0xE4,0xA5,0xA3,0x70,0x3A,0xA6,0x4C,0x9F,0x42,0xBC};
    //std::vector<unsigned char> key = {0xac,0x77,0x66,0xf3,0x19,0xfa,0xdc,0x21,0x28,0xd1,0x29,0x41,0x57,0x5c,0x00,0x6a};
    //std::vector<unsigned char> data(16,0x42);
    std::vector<unsigned char> key(16,0x41);
    std::vector<unsigned char> cipher = c.Encrypt(data,key);
    //PrintVector(cipher);
    //PrintVectorWOSpaces(cipher);

    std::vector<unsigned char> decrypted = c.Decrypt(cipher,key);
    std::string decrypted_string = BytesToS(decrypted);
    std::cout<<decrypted_string;
    //PrintVector(decrypted);






    //std::cout<<(int)f.GetMul(0xed*4);
    //std::cout<<(int)f.CalculateInverseNum(0xe,0xed)<<"\n";
        

    return 0;
}
