#ifndef AES_FUNCTIONS
#define AES_FUNCTIONS
class AESFunctions{
public:
    AESFunctions();
    ~AESFunctions();
    void RotWord(unsigned char word[4],int amount);
    void SubBytes(unsigned char state[][4]);
    void ShiftRow(unsigned char state[][4]);
    unsigned char IfTwo(unsigned char to_mul);
    unsigned char CalculateNum(unsigned char mul, unsigned char to_mul);
    void MixColumn(unsigned char state[][4]);
   
};
#endif