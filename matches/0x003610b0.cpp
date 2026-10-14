extern "C" __int64 __cdecl Find(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager_3610b0 {
    void Init(__int64*, __int64*, int, int);
};
extern Manager_3610b0 manager_3610b0;
struct Pair_3610b0 {
    __int64 property, meta;
};
void __cdecl FUN_003610b0() {
    Pair_3610b0 p;
    p.property = Find("Property", 0, 0);
    p.meta = Find("Meta", 0, 0);
    manager_3610b0.Init(&p.meta, &p.property, 0xa0, 4);
    atexit(cleanup);
}