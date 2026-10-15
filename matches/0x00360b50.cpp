extern "C" __int64 __cdecl Lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Finish();
class Registry {
  public:
    void Register(const __int64*, const __int64*, int, int);
};
extern Registry gRegistry;
void __cdecl Target() {
    __int64 a = Lookup("SeqActionSilence", 0, 0);
    __int64 b = Lookup("Runtime_Sequence", 0, 0);
    gRegistry.Register(&b, &a, 0x1c, 4);
    atexit(Finish);
}
