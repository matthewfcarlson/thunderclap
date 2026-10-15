struct Pair {
    unsigned a, b;
};
extern char name1[], name2[];
extern Pair __cdecl make(const char*, int, int);
struct Registry {
    void add(Pair*, Pair*, int, int);
};
extern Registry registry;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_003605a0() {
    Pair a = make(name1, 0, 0);
    Pair b = make(name2, 0, 0);
    registry.add(&b, &a, 16, 4);
    atexit(cleanup);
}