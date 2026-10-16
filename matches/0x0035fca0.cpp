class Obj {
  public:
    void Init();
};
extern Obj gObj;
extern "C" void __cdecl cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_0035fca0() {
    gObj.Init();
    atexit(cleanup);
}