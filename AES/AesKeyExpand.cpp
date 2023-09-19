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

