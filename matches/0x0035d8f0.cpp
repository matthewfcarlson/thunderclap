struct Pair {
    int lo;
    int hi;
};

extern Pair __cdecl Lookup(const char*);

extern int g_lo;
extern int g_hi;

void __cdecl FUN_0035d8f0() {
    Pair p = Lookup("Header");
    g_lo = p.lo;
    g_hi = p.hi;
}
