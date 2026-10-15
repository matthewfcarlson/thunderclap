extern "C" __int64 __cdecl Lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
extern const char mixerName[];
extern const char runtimeName[];
class Registry {
  public:
    void Init(const __int64*, const __int64*, int, int);
};
extern Registry registry;
void __cdecl FUN_0035f440() {
    __int64 mixer = Lookup(mixerName, 0, 0);
    __int64 runtime = Lookup(runtimeName, 0, 0);
    registry.Init(&runtime, &mixer, 28, 4);
    atexit(Cleanup);
}