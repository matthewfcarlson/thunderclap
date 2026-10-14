extern "C" unsigned __int64 __cdecl make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Obj_3611d0 {
  public:
    void Init(unsigned __int64*, unsigned __int64*, int, int);
};
extern Obj_3611d0 globalObj_3611d0;
void target() {
    unsigned __int64 a = make("OmHalStream Temp Aligned Stream Mem", 0, 0);
    unsigned __int64 b = make("Temp", 0, 0);
    globalObj_3611d0.Init(&b, &a, 0x4000, 0x80);
    atexit(cleanup);
}