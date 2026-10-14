struct Pair_35d8f0 {
    int lo;
    int hi;
};

extern Pair_35d8f0 __cdecl Lookup(const char*);

extern int g_lo_35d8f0;
extern int g_hi_35d8f0;

void __cdecl FUN_0035d8f0() {
    Pair_35d8f0 p = Lookup("Header");
    g_lo_35d8f0 = p.lo;
    g_hi_35d8f0 = p.hi;
}
