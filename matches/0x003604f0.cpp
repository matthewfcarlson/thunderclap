typedef unsigned __int64 U64;
extern U64 __cdecl Hash(const char*, int, int);
class Registry {
  public:
    void Init(U64*, U64*, int, int);
};
extern Registry gRegistry;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl target() {
    U64 a = Hash("ChannelVolumeFadeBehaviour", 0, 0);
    U64 b = Hash("Runtime_Sequence", 0, 0);
    gRegistry.Init(&b, &a, 0x24, 4);
    atexit(cleanup);
}