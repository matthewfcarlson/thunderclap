extern void __cdecl FUN_00363f30();
extern void __cdecl _atexit(void (*func)());
struct Obj {
    void Init(const char*, float);
};
extern Obj gObj;
void FUN_0035e340() {
    gObj.Init("sound/rsd", 0.0f);
    _atexit(FUN_00363f30);
}
