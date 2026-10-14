struct Pair {
    unsigned int lo, hi;
};
extern int gLoader;
extern Pair gResult;
extern "C" Pair __cdecl FUN_002672f0(int a, int b, int c);
Pair __cdecl FUN_0035f110() {
    gResult = FUN_002672f0(gLoader, 0, 0);
    return gResult;
}
