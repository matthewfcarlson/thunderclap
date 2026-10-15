struct Pair {
    unsigned a, b;
};
extern Pair __cdecl make(const char*, int, int);
extern const char n1[], n2[];
struct Registry {
    void init(const Pair*, const Pair*, int, int);
};
extern Registry reg;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_003602b0() {
    Pair x = make(n1, 0, 0);
    Pair y = make(n2, 0, 0);
    reg.init(&y, &x, 16, 4);
    atexit(cleanup);
}