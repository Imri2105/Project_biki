#ifndef AES_KEY_EXPAND
#define AES_KEY_EXPAND
class AESKeyExpand{
    private:
        unsigned char key[4][4];
    public:
        AESKeyExpand();
        ~AESKeyExpand();
        void RotWord(unsigned char word[4],int  = 1);
        void SubKeyBytes(unsigned char word[4]);
        void GetNextKey();
        void G_Function();
    //more functions to be written
};
#endif