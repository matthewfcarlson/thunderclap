extern "C" void __cdecl FUN_00363df0();
extern "C" int __cdecl _atexit(void(__cdecl*)(void));
struct Reg {
    void Fn(const char*, int);
};
extern Reg gReg;
void __cdecl FUN_0035d400() {
    gReg.Fn("sound/rsd", 0);
    _atexit(FUN_00363df0);
}
