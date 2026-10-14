struct Mgr {
    void Run();
};
extern Mgr g4e5cf8;
extern void Fn_003641a0();
extern int __cdecl atexit(void (*f)());

void __cdecl FUN_0035f300() {
    g4e5cf8.Run();
    atexit((void (*)())(unsigned long)Fn_003641a0);
}
