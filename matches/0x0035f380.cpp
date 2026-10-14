extern char Mixer[];
extern char Runtime_Mix[];
extern "C" __int64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl finish();
class Manager {
  public:
    void init(__int64*, __int64*, int, int);
};
Manager gManager;
void target() {
    __int64 a = lookup(Mixer, 0, 0);
    __int64 b = lookup(Runtime_Mix, 0, 0);
    gManager.init(&b, &a, 48, 4);
    atexit(finish);
}