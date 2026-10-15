extern "C" unsigned __int64 __cdecl hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Registry {
  public:
    void init(unsigned __int64*, unsigned __int64*, int, int);
};
extern Registry registry;
void FUN_00360670() {
    unsigned __int64 a = hash("SeqActionVarVolume", 0, 0);
    unsigned __int64 b = hash("Runtime_Sequence", 0, 0);
    registry.init(&b, &a, 16, 4);
    atexit(cleanup);
}