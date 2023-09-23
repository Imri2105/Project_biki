#include "pch.hpp"
#include "Utils.hpp"
#include "boxes.hpp"
#include "AesKeyExpand.hpp"


AESKeyExpand::AESKeyExpand(){
    this->round = 0;
    std::cout<<"AES_KEY OBJECT CREATED";
}

AESKeyExpand::~AESKeyExpand(){
    std::cout<<"AES_KEY OBJECT DESTROYED";
}

void AESKeyExpand::G_Function(unsigned char * word){
    RotateOnce(word, 4); // ? @zada check if 4 is the correct num 
    SubKeyBytes(word);
    word[0]^=GetRcon(this->round);
}

void AESKeyExpand::ExpendKey(unsigned char key[4][4]) {
    for (int j = 0; j < 4; j++){
        SetNewWord(key, j);
    }
    this->round +=1;
}

void AESKeyExpand::SetNewWord(unsigned char key[4][4], int index){
    /*
    Logic:
        [word 0], [word 1], [word 2], [word 3]
    after SetNewWord: 
        [word 4 (new)], [word 1], [word 2], [word 3]
    after ExpendKey:
        [word 4 (new)], [word 5 (new)], [word 6 (new)], [word 7 (new)]
    */
    if (index == 0){
        unsigned char * temp_word = &key[0][3];
        this->G_Function(temp_word);
        for (int i = 0; i < 4; i++){
            key[i][index] ^= temp_word[i];
        }
    }
    else{
        for (int i = 0; i<4; i++){
            key[i][index-1] ^= key[i][index];
        }
    }
}


// check if need:
void AESKeyExpand::RotWord(unsigned char word[4], int amount){
    for(int i = 0; i < amount; i++){
        RotateOnce(word, 4);
    }
}

void AESKeyExpand::SubKeyBytes(unsigned char word[4]){
    for(int i = 0; i < 4; i++){
        word[i] = SubByte(word[i]);
    }
}

