typedef unsigned __int64 U64;
extern "C" U64 __cdecl Hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl Cleanup();
class Registry {
  public:
    void Register(U64*, U64*, int, int);
};
extern Registry gRegistry;
void FUN_00361690() {
    U64 a = Hash("HalRsdFileStream", 0, 0);
    U64 b = Hash("Runtime_Hal", 0, 0);
    gRegistry.Register(&b, &a, 0x48, 4);
    atexit(Cleanup);
}