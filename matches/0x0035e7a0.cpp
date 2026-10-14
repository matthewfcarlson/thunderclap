struct Pair_35e7a0 {
    int lo, hi;
};
extern "C" Pair_35e7a0 __cdecl FUN_0027b020(const char*);
struct Obj_35e7a0 {
    int a;
    int b;
};
Obj_35e7a0 g_b004e22e8;
void FUN_0035e7a0() {
    Pair_35e7a0 r = FUN_0027b020("golfBall_golfBall");
    g_b004e22e8.a = r.lo;
    g_b004e22e8.b = r.hi;
}
