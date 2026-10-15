extern "C" __int64 __cdecl make(const char*, int, int);
struct Manager {
    void init(__int64*, __int64*, int, int);
};
extern Manager manager;
extern char seqCondition[];
extern char runtimeSequence[];
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_0035ff30() {
    __int64 first = make(seqCondition, 0, 0);
    __int64 second = make(runtimeSequence, 0, 0);
    manager.init(&second, &first, 16, 4);
    atexit(cleanup);
}