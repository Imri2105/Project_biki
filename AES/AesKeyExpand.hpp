#ifndef AES_KEY_EXPAND
#define AES_KEY_EXPAND
class AESKeyExpand{
    public:
        AESKeyExpand();
        ~AESKeyExpand();
        void RotWord(std::vector<unsigned char> &word, int = 1);
        void SubKeyBytes(std::vector<unsigned char> &word);
        void G_Function(std::vector<unsigned char> &word, int round);
        void ExpandKey(matrix &key,int round);
        void SetNewWord(matrix &key, int index, int round);
    //more functions to be written 
        std::vector<matrix> GetRoundKeys(matrix key, int round_amount);
};
#endif