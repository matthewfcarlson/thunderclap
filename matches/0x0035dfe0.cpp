struct Hash {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Hash __cdecl FUN_0027b020(const char*);
extern unsigned int g_lo, g_hi;

void __cdecl FUN_0035dfe0() {
    Hash h = FUN_0027b020((const char*)0x400488);
    g_lo = h.lo;
    g_hi = h.hi;
}
