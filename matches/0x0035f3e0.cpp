typedef unsigned __int64 U64;
extern U64 __cdecl make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
class Registry {
  public:
    void registerPair(U64*, U64*, int, int);
};
extern Registry registry;
void init() {
    U64 a = make("MixerMix", 0, 0);
    U64 b = make("Runtime_Mix", 0, 0);
    registry.registerPair(&b, &a, 0x38, 4);
    atexit(cleanup);
}
