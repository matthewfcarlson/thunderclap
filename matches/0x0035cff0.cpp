extern "C" __int64 __cdecl FUN_0027b020(const char* arg);
int gResultLo;
int gResultHi;
void __cdecl FUN_0035cff0() {
    extern const char gLabel[];
    __int64 r = FUN_0027b020(gLabel);
    gResultLo = (int)r;
    gResultHi = (int)((unsigned __int64)r >> 32);
}
