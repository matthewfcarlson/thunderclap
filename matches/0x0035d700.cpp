extern "C" void __cdecl FUN_00363e20();
// cl-flags: /O1
extern "C" void _atexit(void (*)(void));
struct Mgr {
    void Reg(const char* name, int a);
};
void __cdecl FUN_0035d700() {
    ((Mgr*)0x4ddf68)->Reg("sound/rsd", 0);
    _atexit(FUN_00363e20);
}
