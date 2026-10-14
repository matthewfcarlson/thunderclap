struct Helper {
    void Run();
};
extern Helper gHelper;
extern "C" int __cdecl _atexit(void (*)());
extern void __cdecl FUN_00364570();
void __cdecl FUN_00360a80() {
    gHelper.Run();
    _atexit((void (*)())FUN_00364570);
}
