extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern unsigned int g_lo;
extern unsigned int g_hi;

void FUN_0035c760() {
    unsigned long long r = FUN_0027b020("missilesoldier");
    g_lo = (unsigned int)r;
    g_hi = (unsigned int)(r >> 32);
}
