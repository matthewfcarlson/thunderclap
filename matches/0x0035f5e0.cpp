extern char trackName[];
extern char sequenceName[];
extern "C" __int64 __cdecl getName(const char*, int, int);
class Registry {
  public:
    void Init(__int64*, __int64*, int, int);
};
extern Registry registry;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_0035f5e0() {
    __int64 track = getName(trackName, 0, 0);
    __int64 sequence = getName(sequenceName, 0, 0);
    registry.Init(&sequence, &track, 0x20, 4);
    atexit(cleanup);
}