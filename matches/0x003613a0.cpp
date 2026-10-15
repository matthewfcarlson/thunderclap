struct Pair {
    int a, b;
};
struct Registry {
    void Init(Pair*, Pair*, int, int);
};
extern Registry registry;
extern Pair __cdecl Get(const char*, int, int);
extern int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
extern const char name1[], name2[];
void FUN_003613a0() {
    Pair p = Get(name1, 0, 0);
    Pair q = Get(name2, 0, 0);
    registry.Init(&q, &p, 12, 4);
    atexit(Cleanup);
}