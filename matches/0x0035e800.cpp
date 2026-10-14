extern "C" struct Pair {
    unsigned int lo;
    unsigned int hi;
} __cdecl FUN_0027b020(const char*);
extern unsigned int g1, g2;
void FUN_0035e800() {
    struct Pair r = FUN_0027b020("hulk");
    g1 = r.lo;
    g2 = r.hi;
}
