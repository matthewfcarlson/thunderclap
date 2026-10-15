typedef __int64 I64;
extern "C" I64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Registry {
  public:
    void init(I64*, I64*, int, int);
};
extern Registry gRegistry;
void __cdecl FUN_00360450() {
    I64 a = lookup("SeqActionChannelVolumes", 0, 0);
    I64 b = lookup("Runtime_Sequence", 0, 0);
    gRegistry.init(&b, &a, 16, 4);
    atexit(cleanup);
}