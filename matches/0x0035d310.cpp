extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363d50();
struct Pair {
    int a, b;
};
Pair values[13];
void init() {
    Pair* p = values;
    int n = 13;
    do {
        p->a = 0;
        p->b = 0;
        ++p;
    } while (--n);
    atexit(FUN_00363d50);
}