#include "pch.hpp"
#include "Utils.hpp"
#include "boxes.hpp"
#include "AesKeyExpand.hpp"


AESKeyExpand::AESKeyExpand(){
    //to be filled
}

AESKeyExpand::~AESKeyExpand(){
    //to be filled
}





void AESKeyExpand::RotWord(unsigned char word[4],int amount){
    for(int i = 0;i<amount;i++){
        RotateOnce(word,4);
    }
}

void AESKeyExpand::SubKeyBytes(unsigned char word[4]){
    for(int i = 0;i<4;i++){
        word[i] = SubByte(word[i]);
    }
}

