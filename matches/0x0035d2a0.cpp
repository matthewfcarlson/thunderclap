extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363d10();
struct Pair {
    int a, b;
};
volatile Pair g[11];
void init() {
    volatile Pair* p = g;
    int n = 11;
    int z = 0;
    do {
        p->a = z;
        p->b = z;
        ++p;
    } while (--n);
    atexit(FUN_00363d10);
}