typedef unsigned __int64 U64;
extern U64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
class Registry {
  public:
    void init(U64*, U64*, int, int);
};
extern Registry registry;
void __cdecl FUN_0035f960() {
    U64 a = lookup("HalListener", 0, 0);
    U64 b = lookup("Runtime_Hal", 0, 0);
    registry.init(&b, &a, 64, 4);
    atexit(cleanup);
}