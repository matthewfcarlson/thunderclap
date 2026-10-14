typedef unsigned __int64 U64_361630;
extern U64_361630 __cdecl Find(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
class Registry_361630 {
  public:
    void Add(U64_361630*, U64_361630*, int, int);
};
extern Registry_361630 gRegistry_361630;
void __cdecl FUN_00361630() {
    U64_361630 a = Find("HalRsdFileHeader", 0, 0);
    U64_361630 b = Find("Runtime_Hal", 0, 0);
    gRegistry_361630.Add(&b, &a, 0x1a4, 4);
    atexit(Cleanup);
}