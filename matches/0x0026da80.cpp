extern "C" void FUN_00272540(void);
extern "C" void FUN_0026d990(void*);
extern void (__stdcall *g_initCS)(void*);
void FUN_0026da80(int unused) {
    g_initCS((void*)0x52a188);
    *(volatile unsigned char*)0x52a184 = 1;
    FUN_00272540();
    FUN_0026d990((void*)0x52a130);
}
