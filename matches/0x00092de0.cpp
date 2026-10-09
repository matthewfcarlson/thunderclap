extern "C" unsigned int __stdcall FUN_00092940(unsigned int);
extern "C" unsigned char __stdcall FUN_00092de0(unsigned int x) {
    if ((int)x >= 0 && (int)x < 0x2fe)
        return (unsigned char)FUN_00092940(x);
    return 0;
}