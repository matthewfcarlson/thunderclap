extern "C" int __cdecl _atexit(void (*)());
struct G {
    void Init();
};
extern G gGlobal;
void __cdecl FUN_003603e0() {
    gGlobal.Init();
    _atexit((void (*)())0x364460);
}
