class Obj {
  public:
    void Init(void* a, int b);
};
extern Obj gObj;
extern void __cdecl _atexit(void (*f)());
extern void FUN_00364820();

void FUN_00363ad0() {
    gObj.Init((void*)0x55dfc0, 0x8000);
    _atexit(FUN_00364820);
}
