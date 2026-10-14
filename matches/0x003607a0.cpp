struct Obj {
    void Fn();
};
extern Obj gObj;
extern void __cdecl FUN_003644f0();
extern void __cdecl _atexit(void(__cdecl* func)());
void __cdecl FUN_003607a0() {
    gObj.Fn();
    _atexit(FUN_003644f0);
}
