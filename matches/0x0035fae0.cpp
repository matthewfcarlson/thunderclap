extern "C" int atexit(void (*)(void));
extern void __cdecl FUN_00364300();
struct G {
    void f();
};
void __cdecl FUN_0035fae0() {
    ((G*)0x4e64d8)->f();
    atexit((void (*)(void))FUN_00364300);
}
