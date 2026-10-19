typedef unsigned char bool8;
struct ThisWrap_002edc00 {
    bool8 FUN_002ed7a0(unsigned int);
    unsigned char FUN_002edc00(unsigned int param_1);
};
unsigned char ThisWrap_002edc00::FUN_002edc00(unsigned int param_1) {
    return (unsigned char)(this->FUN_002ed7a0(param_1) != 0);
}