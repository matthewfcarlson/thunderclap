extern "C" struct Pair_35e5c0 {
    int lo;
    int hi;
};
extern "C" Pair_35e5c0 __cdecl FUN_0027b020(const char* s);
extern int g_a;
extern int g_b;
void FUN_0035e5c0() {
    Pair_35e5c0 r = FUN_0027b020("electric");
    g_a = r.lo;
    g_b = r.hi;
}
