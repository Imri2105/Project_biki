#ifndef AES_KEY_EXPAND
#define AES_KEY_EXPAND
class AESKeyExpand{
    private:
        matrix key;
        int round;
    public:
        AESKeyExpand();
        ~AESKeyExpand();
        void RotWord(std::vector<unsigned char> &word, int = 1);
        void SubKeyBytes(std::vector<unsigned char> &word);
        void G_Function(std::vector<unsigned char> &word);
        void ExpendKey(matrix &key);
        void SetNewWord(matrix &key, int index);
    //more functions to be written
};
#endif