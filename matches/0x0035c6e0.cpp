struct Pair_35c6e0 {
    int lo;
    int hi;
};
extern "C" Pair_35c6e0 FUN_0027b020(const char*);
extern int g_4dc030;
extern int g_4dc034;
void FUN_0035c6e0() {
    Pair_35c6e0 x = FUN_0027b020("golfBall_golfBall");
    g_4dc030 = x.lo;
    g_4dc034 = x.hi;
}
