typedef unsigned __int64 U64;
extern "C" U64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Manager {
  public:
    void Init(U64*, U64*, int, int);
};
extern Manager manager;
void __cdecl target() {
    U64 a = lookup("ChannelSendVolumeArray", 0, 0);
    U64 b = lookup("Runtime_Sequence", 0, 0);
    manager.Init(&b, &a, 256, 4);
    atexit(cleanup);
}