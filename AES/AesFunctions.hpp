#ifndef AES_FUNCTIONS
#define AES_FUNCTIONS
class AESFunctions{
public:
    AESFunctions();
    ~AESFunctions();
    void SubBytes(unsigned char state[][4]);
    void ShiftRow(unsigned char state[][4]);
    unsigned char IfTwo(unsigned char to_mul);
    unsigned char CalculateNum(unsigned char mul, unsigned char to_mul);
    void MixColumn(unsigned char state[][4]);
    void AddRoundKey(unsigned char state[][4],unsigned char key[][4]);
    void Round(unsigned char state[][4],unsigned char key[][4],int round_num);
};
#endif