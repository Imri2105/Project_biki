#include "pch.hpp"
#include "Utils.hpp"
#include "boxes.hpp"
#include "AesKeyExpand.hpp"


AESKeyExpand::AESKeyExpand(){
    //currently empty
}

AESKeyExpand::~AESKeyExpand(){
    //currently empty
}

void AESKeyExpand::G_Function(std::vector<unsigned char> &word, int round){
    RotateOnce(word);
    SubKeyBytes(word);
    word[0]^=GetRcon(round-1);
}

void AESKeyExpand::ExpandKey(matrix &key, int round) {
    for (int j = 0; j < 4; j++){
        SetNewWord(key, j,round);
    }
}

void AESKeyExpand::SetNewWord(matrix &key, int index,int round){
    /*
    Logic:
        [word 0], [word 1], [word 2], [word 3]
    after SetNewWord: 
        [word 4 (new)], [word 1], [word 2], [word 3]
    after ExpendKey:
        [word 4 (new)], [word 5 (new)], [word 6 (new)], [word 7 (new)]
    */
    if (index == 0){
        std::vector<unsigned char> temp_word = key[3];
        this->G_Function(temp_word,round);
        for (int i = 0; i < 4; i++){
            key[index][i] ^= temp_word[i];
        }
    }
    else{
        for (int i = 0; i<4; i++){
            key[index][i] ^= key[index-1][i];
        }
    }
}


void AESKeyExpand::RotWord(std::vector<unsigned char> &word, int amount){
    for(int i = 0; i < amount; i++){
        RotateOnce(word);
    }
}

void AESKeyExpand::SubKeyBytes(std::vector<unsigned char> &word){
    for(int i = 0; i < 4; i++){
        word[i] = SubByte(word[i]);
    }
}

std::vector<matrix> AESKeyExpand::GetRoundKeys(matrix key, int round_amount){
    std::vector <matrix> keys;
    keys.insert(keys.begin(),key);
    for(int i =1;i<=round_amount;i++){
        this->ExpandKey(key,i);
        keys.insert(keys.begin(),key);
    }
    return keys;
}

