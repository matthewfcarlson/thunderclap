struct Helper_360170 {
    void Run();
};
extern int __cdecl _atexit(void(__cdecl*)(void));
extern void __cdecl FUN_00364400(void);
void __cdecl FUN_00360170() {
    ((Helper_360170*)0x4e6a68)->Run();
    _atexit((void(__cdecl*)(void))(long)FUN_00364400);
}
