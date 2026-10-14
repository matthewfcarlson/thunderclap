typedef unsigned __int64 U64;
extern U64 __cdecl lookup(const char*, int, int);
struct Manager {
    void init(U64*, U64*, int, int);
};
extern Manager manager;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_0035f870() {
    U64 first = lookup("HalStreamPlayer", 0, 0);
    U64 second = lookup("Runtime_Hal", 0, 0);
    manager.init(&second, &first, 0xd8, 4);
    atexit(cleanup);
}