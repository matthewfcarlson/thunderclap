extern "C" void __cdecl FUN_00364460();
extern "C" int __cdecl _atexit(void (*)());
struct G_3603e0 {
    void Init();
};
extern G_3603e0 gGlobal_3603e0;
void __cdecl FUN_003603e0() {
    gGlobal_3603e0.Init();
    _atexit(FUN_00364460);
}
