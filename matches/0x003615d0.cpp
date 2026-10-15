extern "C" __int64 __cdecl lookup(const char*, int, int);
class Manager {
  public:
    void init(__int64*, __int64*, int, int);
};
extern Manager global;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl FUN_003615d0() {
    struct Pair {
        __int64 a;
        __int64 b;
    } p;
    p.a = lookup("HalRadicalAdpcmDecodeStream", 0, 0);
    p.b = lookup("Runtime_Hal", 0, 0);
    global.init(&p.b, &p.a, 32, 4);
    atexit(cleanup);
}
