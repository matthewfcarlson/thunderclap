typedef unsigned __int64 U64;
extern U64 __cdecl Hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
struct Registry {
    void Register(U64*, U64*, int, int);
};
extern Registry gRegistry;
void Init() {
    U64 a = Hash("SeqCommandLogicRepeat", 0, 0);
    U64 b = Hash("Runtime_Sequence", 0, 0);
    gRegistry.Register(&b, &a, 24, 4);
    atexit(Cleanup);
}