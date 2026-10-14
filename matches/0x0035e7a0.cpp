struct Pair {
    int lo, hi;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
struct Obj {
    int a;
    int b;
};
Obj g_b004e22e8;
void FUN_0035e7a0() {
    Pair r = FUN_0027b020("golfBall_golfBall");
    g_b004e22e8.a = r.lo;
    g_b004e22e8.b = r.hi;
}
