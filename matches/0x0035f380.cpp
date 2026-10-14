extern char Mixer[];
extern char Runtime_Mix[];
extern "C" __int64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl finish();
class Manager_35f380 {
  public:
    void init(__int64*, __int64*, int, int);
};
Manager_35f380 gManager_35f380;
void target() {
    __int64 a = lookup(Mixer, 0, 0);
    __int64 b = lookup(Runtime_Mix, 0, 0);
    gManager_35f380.init(&b, &a, 48, 4);
    atexit(finish);
}