struct Pair_35e800 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Pair_35e800 __cdecl FUN_0027b020(const char*);
extern unsigned int g1_35e800, g2;
void FUN_0035e800() {
    struct Pair_35e800 r = FUN_0027b020("hulk");
    g1_35e800 = r.lo;
    g2 = r.hi;
}
