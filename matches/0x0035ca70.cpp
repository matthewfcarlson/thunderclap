extern "C" unsigned long long __cdecl GetHash(const char*);
extern unsigned int g_lo_35ca70;
extern unsigned int g_hi_35ca70;

void FUN_0035ca70() {
    unsigned long long h = GetHash("punching");
    g_lo_35ca70 = (unsigned int)h;
    g_hi_35ca70 = (unsigned int)(h >> 32);
}
