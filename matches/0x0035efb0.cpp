extern "C" unsigned long long __cdecl FUN_002672f0(const void* p, int a, int b);
extern const void* g_4ca248;
extern unsigned int g_4e5b68;
extern unsigned int g_4e5b6c;

void FUN_0035efb0() {
    unsigned long long r = FUN_002672f0(g_4ca248, 0, 0);
    g_4e5b68 = (unsigned int)r;
    g_4e5b6c = (unsigned int)(r >> 32);
}
