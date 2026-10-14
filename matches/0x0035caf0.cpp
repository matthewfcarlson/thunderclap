extern "C" unsigned long long __cdecl Hash64(const char*);
extern unsigned int g_hashLo;
extern unsigned int g_hashHi;
void FUN_0035caf0() {
    unsigned long long h = Hash64("climbing");
    g_hashLo = (unsigned int)h;
    g_hashHi = (unsigned int)(h >> 32);
}
