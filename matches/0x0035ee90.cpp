struct Pair {
    int lo;
    int hi;
};
extern Pair __cdecl Lookup(const char*, int, int);
extern int g_lo;
extern int g_hi;

void __cdecl FUN_0035ee90() {
    Pair p = Lookup("Template", 0, 0);
    g_lo = p.lo;
    g_hi = p.hi;
}
