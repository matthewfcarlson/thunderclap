struct Helper_360a80 {
    void Run();
};
extern Helper_360a80 gHelper_360a80;
extern "C" int __cdecl _atexit(void (*)());
extern void __cdecl FUN_00364570();
void __cdecl FUN_00360a80() {
    gHelper_360a80.Run();
    _atexit((void (*)())FUN_00364570);
}
