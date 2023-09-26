#include "AES/pch.hpp"
#include "AES/AesFunctions.hpp"
#include "AES/Utils.hpp"
#include "AES/AesKeyExpand.hpp"

int main(int argc, char const *argv[]){ //checks if mixColumn works, it works.
    
    AESFunctions aes_class = AESFunctions();
    /*AESKeyExpand aeskey_class = AESKeyExpand();
    unsigned char word[] = {0x27,0x39,0x95,0xf1};
    /*unsigned char state[4][4] = {{0xEA,0x04,0X65,0x85},{0x83,0x45,0x5D,0x96},{0x5C,0x33,0x98,0xB0},{0xF0,0x2D,0xAD,0xC5}};
    //unsigned char state1[4][4] = {{0x87,0xF2,0X4D,0x97},{0x6E,0x4C,0x90,0xEC},{0x46,0xE7,0x4A,0xC3},{0xA6,0x8C,0xD8,0x95}};
    //PrintState(state1);
    //std::cout<<"------------------------------"<<std::endl;
    //aes_class.ShiftRow(state1);
    //PrintState(state1);
    aeskey_class.RotWord(word);
    PrintArray(word, 4);*/

    std::vector<unsigned char> v;
    for(int i = 0;i<1;i++){
        v.push_back(i);
    }
    PrintVector(v);
    aes_class.Padding(v,aes_class.BLOCK_SIZE);
    PrintVector(v);
    aes_class.UnPad(v,aes_class.BLOCK_SIZE);
    PrintVector(v);
    return 0;
}
