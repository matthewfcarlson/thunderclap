extern "C" char DAT_0052a130[];
extern "C" char DAT_0052a184[];
extern "C" char DAT_0052a188[];
extern "C" void FUN_00272540(void);
extern "C" void FUN_0026d990(void*);
extern void(__stdcall* g_initCS)(void*);
void FUN_0026da80(int unused) {
    g_initCS((void*)((int)DAT_0052a188));
    *(volatile unsigned char*)((int)DAT_0052a184) = 1;
    FUN_00272540();
    FUN_0026d990((void*)((int)DAT_0052a130));
}
