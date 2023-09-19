#include "AES/pch.hpp"
#include "AES/AesFunctions.hpp"
#include "AES/Utils.hpp"

int main(int argc, char const *argv[]){ //checks if mixColumn works, it works.
    AESFunctions aes_class = AESFunctions();
    unsigned char word[] = {0x27,0x39,0x95,0xf1};
    //unsigned char state[4][4] = {{0xEA,0x04,0X65,0x85},{0x83,0x45,0x5D,0x96},{0x5C,0x33,0x98,0xB0},{0xF0,0x2D,0xAD,0xC5}};
    //aes_class.SubBytes(state);
    //PrintState(state);
    aes_class.RotWord(word,1);
    PrintArray(word,sizeof(word)/sizeof(word[0]));
    return 0;
}
