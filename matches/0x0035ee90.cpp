struct Pair {
    int lo;
    int hi;
};
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern int g_lo;
extern int g_hi;

void __cdecl FUN_0035ee90() {
    unsigned __int64 p = FUN_002672f0("Template", 0, 0);
    g_lo = (int)p;
    g_hi = (int)(p >> 32);
}
