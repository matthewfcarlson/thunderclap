extern "C" __int64 __cdecl Lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
class Registry {
  public:
    void Init(__int64*, __int64*, int, int);
};
extern Registry gRegistry;
void __cdecl FUN_00360f80() {
    __int64 b = Lookup("SeqBuss", 0, 0);
    __int64 a = Lookup("Data_Sequence", 0, 0);
    gRegistry.Init(&a, &b, 0x14, 4);
    atexit(Cleanup);
}