#include "pch.hpp"
#include "Utils.hpp"
#include "boxes.hpp"
#include "AesKeyExpand.hpp"


AESKeyExpand::AESKeyExpand(){
    std::cout<<"AES_KEY OBJECT CREATED";
}

AESKeyExpand::~AESKeyExpand(){
    std::cout<<"AES_KEY OBJECT DESTROYED";
}

void AESKeyExpand::G_Function(unsigned char word[4], int round){
    RotateOnce(word);
    SubKeyBytes(word);
    word[0]^=GetRcon(round);
}

void AESKeyExpand::GetNextKey(){

}

void AESKeyExpand::ExpendKey(unsigned char key[4][4]) {
    for (int j = 0; j<4; j++){
        //set_new_word(key, j);
    }
}

void GetNextKey(){
    for (int i=0;i<4;i++){


    }
}

/*
void AESKeyExpand::set_new_word(unsigned char key[4][4], int index){
    if (index == 0){
        for (int i = 0; i<4; i++){
            key[i][index] ^= this->G_Function(key[i][index+3]);
        }
    }
    else{
        for (int i = 0; i<4; i++){
            key[i][index-1] ^= key[i][index];
        }
    }
}
*/

// check if need:
void AESKeyExpand::RotWord(unsigned char word[4],int amount){
    for(int i = 0;i<amount;i++){
        RotateOnce(word);
    }
}

void AESKeyExpand::SubKeyBytes(unsigned char word[4]){
    for(int i = 0;i<4;i++){
        word[i] = SubByte(word[i]);
    }
}

