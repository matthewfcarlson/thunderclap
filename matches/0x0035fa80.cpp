class Obj {
  public:
    void FUN_0025fa00(const char*, int);
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003642e0();
void __cdecl FUN_0035fa80() {
    gObj.FUN_0025fa00("ListenerEffectGc", 0);
    atexit(FUN_003642e0);
}
