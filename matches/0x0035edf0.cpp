struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
extern Pair gPair;
void __cdecl FUN_0035edf0() {
    gPair = FUN_0027b020("golfBall_golfBall");
}