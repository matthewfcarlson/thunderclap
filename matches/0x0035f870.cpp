typedef unsigned __int64 U64_35f870;
extern U64_35f870 __cdecl lookup(const char*, int, int);
struct Manager_35f870 {
    void init(U64_35f870*, U64_35f870*, int, int);
};
extern Manager_35f870 manager_35f870;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_0035f870() {
    U64_35f870 first = lookup("HalStreamPlayer", 0, 0);
    U64_35f870 second = lookup("Runtime_Hal", 0, 0);
    manager_35f870.init(&second, &first, 0xd8, 4);
    atexit(cleanup);
}