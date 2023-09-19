#include "AES/pch.hpp"
#include "AES/AesFunctions.hpp"
#include "AES/Utils.hpp"

int main(int argc, char const *argv[]){ //checks if mixColumn works, it works.
    AESFunctions aes_class = AESFunctions();
    unsigned char state[4][4] = {{0x87,0xF2,0X4D,0x97},{0x6E,0x4C,0x90,0xEC},{0x46,0xE7,0x4A,0xC3},{0xA6,0x8C,0xD8,0x95}};
    aes_class.MixColumn(state);
    PrintState(state);
    return 0;
}
