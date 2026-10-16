extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
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
    atexit(cleanup);
}