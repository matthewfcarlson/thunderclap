class CStaticAllocator_35e6b0 {
  public:
    void Init(int, int, int, int);
};
extern CStaticAllocator_35e6b0 gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl FUN_0035e6b0() {
    gObj.Init(0x100, 0x20, 0xd, 0);
    atexit(cleanup);
}