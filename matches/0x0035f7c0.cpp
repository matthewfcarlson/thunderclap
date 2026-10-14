typedef unsigned __int64 U64_35f7c0;
extern "C" U64_35f7c0 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Manager_35f7c0 {
  public:
    void Init(U64_35f7c0*, U64_35f7c0*, int, int);
};
extern Manager_35f7c0 manager_35f7c0;
void __cdecl target() {
    U64_35f7c0 a = lookup("ChannelSendVolumeArray", 0, 0);
    U64_35f7c0 b = lookup("Runtime_Sequence", 0, 0);
    manager_35f7c0.Init(&b, &a, 256, 4);
    atexit(cleanup);
}