struct Handle {
    int lo, hi;
};
extern "C" Handle __cdecl FUN_0027b020(const char*);
extern int g4e2640;
extern int g4e2644;
void __cdecl FUN_0035ecf0() {
    Handle h = FUN_0027b020("golfBall_golfBall");
    g4e2640 = h.lo;
    g4e2644 = h.hi;
}
