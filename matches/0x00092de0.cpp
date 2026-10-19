struct ThisWrap_00092de0 {
    unsigned int FUN_00092940(unsigned int);
    unsigned char FUN_00092de0(unsigned int x);
};
unsigned char ThisWrap_00092de0::FUN_00092de0(unsigned int x) {
    if ((int)x >= 0 && (int)x < 0x2fe)
        return (unsigned char)this->FUN_00092940(x);
    return 0;
}