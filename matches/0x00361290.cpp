extern "C" __int64 __cdecl hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Holder {
  public:
    void Set(__int64*, __int64*, int, int);
};
extern Holder gHolder;
void target() {
    __int64 a = hash("SeqTrackPlayer", 0, 0);
    __int64 b = hash("Runtime_Sequence", 0, 0);
    gHolder.Set(&b, &a, 0x60, 4);
    atexit(cleanup);
}
