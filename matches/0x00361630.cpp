typedef unsigned __int64 U64;
extern U64 __cdecl Find(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
class Registry {
  public:
    void Add(U64*, U64*, int, int);
};
extern Registry gRegistry;
void __cdecl FUN_00361630() {
    U64 a = Find("HalRsdFileHeader", 0, 0);
    U64 b = Find("Runtime_Hal", 0, 0);
    gRegistry.Add(&b, &a, 0x1a4, 4);
    atexit(Cleanup);
}