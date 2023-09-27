#ifndef AES_FUNCTIONS
#define AES_FUNCTIONS
#include "pch.hpp"
const int degree_8 = 256;
const int degree_9 = 512;
const int degree_10 = 1024;

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
//------------------------------------------------------ end of encryption functions
    void InverseShiftRow(matrix &state);
    void InverseSubBytes(matrix &state);
    unsigned char GetMul(int value);
    unsigned char MulNum(int degree, unsigned char to_mul);
    unsigned char CalculateInverseNum(unsigned char mul, unsigned char to_mul);
    void InverseMixColumn(matrix &state);
    void DecryptRound(matrix &state, matrix &round_key, int round_num);
};
#endif