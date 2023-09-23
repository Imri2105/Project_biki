#ifndef AES_KEY_EXPAND
#define AES_KEY_EXPAND
class AESKeyExpand{
    private:
        unsigned char key[4][4];
        int round;
    public:
        AESKeyExpand();
        ~AESKeyExpand();
        void RotWord(unsigned char word[4], int = 1);
        void SubKeyBytes(unsigned char word[4]);
        void G_Function(unsigned char * word);
        void ExpendKey(unsigned char key[4][4]);
        void SetNewWord(unsigned char key[4][4], int index);
    //more functions to be written
};
#endif