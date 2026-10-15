extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
extern "C" __int64 __cdecl lookup(const char*, int, int);
class Registry {
  public:
    void init(__int64*, __int64*, int, int);
};
extern Registry registry;
void __cdecl FUN_00360aa0() {
    __int64 a = lookup("SeqActionStream", 0, 0);
    __int64 b = lookup("Runtime_Sequence", 0, 0);
    registry.init(&b, &a, 44, 4);
    atexit(cleanup);
}