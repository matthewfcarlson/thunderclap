extern void __stdcall init();
struct Pair {
    int a, b;
};
Pair* f(Pair* dst, Pair* src) {
    init();
    *dst = *src;
    return dst;
}