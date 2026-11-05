class Obj {
  public:
    void FUN_0024e670();
};
extern Obj gObj;
extern "C" void __cdecl FUN_00364350();
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_0035fca0() {
    gObj.FUN_0024e670();
    atexit(FUN_00364350);
}