class Obj {
  public:
    void FUN_002524e0();
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_003644b0();
void __cdecl FUN_00360600() {
    gObj.FUN_002524e0();
    atexit(FUN_003644b0);
}
