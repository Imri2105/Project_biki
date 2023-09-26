#ifndef AES_FUNCTIONS
#define AES_FUNCTIONS
#include "pch.hpp"

class AESFunctions{
public: 
    const size_t BLOCK_SIZE = 16;
    AESFunctions();
    ~AESFunctions();
    void SubBytes(matrix &state);
    void ShiftRow(matrix &state);
    unsigned char IfTwo(unsigned char to_mul);
    unsigned char CalculateNum(unsigned char mul, unsigned char to_mul);
    void MixColumn(matrix &state);
    void AddRoundKey(matrix &state, matrix &key);
    void Round(matrix &state, matrix &key, int round_num);
    void Padding(std::vector<unsigned char> &data);
    void UnPad(std::vector<unsigned char> &data);
};
#endif