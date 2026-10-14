extern "C" unsigned long long __cdecl GetHash(const char*);
extern unsigned int g_lo;
extern unsigned int g_hi;

void FUN_0035ca70() {
    unsigned long long h = GetHash("punching");
    g_lo = (unsigned int)h;
    g_hi = (unsigned int)(h >> 32);
}
