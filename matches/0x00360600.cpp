class Obj {
  public:
    void Init();
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl Cleanup();
void __cdecl FUN_00360600() {
    gObj.Init();
    atexit(Cleanup);
}
