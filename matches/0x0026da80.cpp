#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"

extern "C" void FUN_00272540(void);
extern "C" void FUN_0026d990(void*);
extern void(__stdcall* g_initCS)(void*);
void FUN_0026da80(int unused) {
    g_initCS((void*)((hulk_intptr)((char*)&DAT_0052a188)));
    *(volatile unsigned char*)((hulk_intptr)DAT_0052a184) = 1;
    FUN_00272540();
    FUN_0026d990((void*)((hulk_intptr)DAT_0052a130));
}
