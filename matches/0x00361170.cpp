extern "C" __int64 Parse(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
void __cdecl Cleanup();
class Registry {
  public:
    void Register(__int64*, __int64*, int, int);
};
extern Registry gRegistry;
void Init() {
    __int64 a = Parse("OmHalStream", 0, 0);
    __int64 b = Parse("Transient", 0, 0);
    gRegistry.Register(&b, &a, 0x1c8, 4);
    atexit(Cleanup);
}