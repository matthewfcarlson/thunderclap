typedef unsigned __int64 U64;
extern U64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Registry {
  public:
    void init(U64*, U64*, int, int);
};
extern Registry registry;
void __cdecl FUN_0035f760() {
    U64 x = lookup("ChannelVolumeArray", 0, 0);
    U64 y = lookup("Runtime_Sequence", 0, 0);
    registry.init(&y, &x, 0x40, 4);
    atexit(cleanup);
}