extern "C" void __cdecl FUN_00254760();
extern "C" void __cdecl FUN_00364590();
extern "C" int atexit(void(__cdecl*)(void));
struct G {
    void f();
};
extern G gG;
extern "C" void __cdecl FUN_00360bb0() {
    gG.f();
    atexit(FUN_00364590);
}
