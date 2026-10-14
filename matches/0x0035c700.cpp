struct Reg {
    void Register(const char* name, int flag);
};
extern Reg gReg;
void FnSound();
void __cdecl FUN_00363af0();
extern "C" int __cdecl _atexit(void(__cdecl* f)());
void __cdecl FUN_0035c700() {
    gReg.Register("sound/rsd", 0);
    _atexit(FUN_00363af0);
}
