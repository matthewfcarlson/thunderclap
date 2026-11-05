#include "decls/data/platform/xbox/core.h"
// data: gFirst_26d8f0 = DAT_0052a180, gLast_26d8f0 = DAT_0052a17c, gLock_26d8f0 = DAT_0052a188

#include "compat/ptr.h"
typedef unsigned int U32_26d8f0;
typedef void(__stdcall* LockFn)(void*);
extern "C" void(__stdcall* DAT_003f2c8c)(void*);   // kernel import slot RtlEnterCriticalSection
extern "C" void(__stdcall* DAT_003f2c88)(void*);   // kernel import slot RtlLeaveCriticalSection
extern "C" void __cdecl FUN_0026d8f0(unsigned int * node) {
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if ((*(void**)&DAT_0052a180) == 0) {
        (*(void**)&DAT_0052a180) = node;
        node[1] = 0;
    } else {
        *(hulk_uintptr*)(*(void**)&DAT_0052a17c) = (hulk_uintptr)node;
        node[1] = (hulk_uintptr)(*(void**)&DAT_0052a17c);
    }
    (*(void**)&DAT_0052a17c) = node;
    node[0] = 0;
    DAT_003f2c88(((char*)&DAT_0052a188));
}