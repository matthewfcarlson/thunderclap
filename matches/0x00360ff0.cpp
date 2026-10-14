extern "C" __int64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
struct Mgr {
    void init(__int64*, __int64*, int, int);
};
extern Mgr mgr;
void __cdecl FUN_00360ff0() {
    __int64 a;
    __int64 b = lookup("HalVoice", 0, 0);
    a = lookup("Runtime_Hal", 0, 0);
    mgr.init(&a, &b, 0x88, 4);
    atexit(cleanup);
}