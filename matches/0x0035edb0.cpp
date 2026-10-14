extern "C" void __cdecl FUN_001e8800();
extern "C" void __cdecl FUN_001e8830();
extern "C" int __cdecl _atexit(void (*)());
extern "C" void __cdecl FUN_003640b0();
struct RegObj {
    void Reg(void*, void*);
};
extern RegObj gRegObj;
void __cdecl FUN_0035edb0() {
    gRegObj.Reg((void*)FUN_001e8800, (void*)FUN_001e8830);
    _atexit((void (*)())FUN_003640b0);
}
