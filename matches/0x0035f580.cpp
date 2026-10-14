extern "C" __int64 lookup(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager {
    void registerTypes(__int64*, __int64*, int, int);
};
extern Manager gManager;
void __cdecl target() {
    __int64 a = lookup("SeqPlayer", 0, 0);
    __int64 b = lookup("Runtime_Sequence", 0, 0);
    gManager.registerTypes(&b, &a, 0xb8, 4);
    atexit(cleanup);
}
