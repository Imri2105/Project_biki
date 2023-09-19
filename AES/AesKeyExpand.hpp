#ifndef AES_KEY_EXPAND
#define AES_KEY_EXPAND
class AESKeyExpand{
    private:
        unsigned char key[4][4];
    
    public:
        AESKeyExpand();
        ~AESKeyExpand();
};
#endif