typedef unsigned __int64 U64;
extern "C" U64 __cdecl getId(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
struct Registry {
    void add(U64*, U64*, int, int);
};
extern Registry registry;
void __cdecl FUN_003608e0() {
    U64 a = getId("SeqActionVarPitchRand", 0, 0);
    U64 b = getId("Runtime_Sequence", 0, 0);
    registry.add(&b, &a, 16, 4);
    atexit(cleanup);
}