extern void __stdcall init();
struct Pair {
    int a, b;
};
extern "C" Pair* FUN_0025ca90(Pair* dst, Pair* src) {
    init();
    *dst = *src;
    return dst;
}