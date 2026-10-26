#include "decls/data/platform/xbox/core.h"
// data: gFirst_26d8f0 = DAT_0052a180, gLast_26d8f0 = DAT_0052a17c, gLock_26d8f0 = DAT_0052a188

#include "compat/ptr.h"
typedef unsigned int U32_26d8f0;
typedef void(__stdcall* LockFn)(void*);
extern LockFn enterFn;
extern LockFn leaveFn;
void __cdecl Target(U32_26d8f0* node) {
    enterFn(((char*)&DAT_0052a188));
    if ((*(void**)&DAT_0052a180) == 0) {
        (*(void**)&DAT_0052a180) = node;
        node[1] = 0;
    } else {
        *(hulk_uintptr*)(*(void**)&DAT_0052a17c) = (hulk_uintptr)node;
        node[1] = (hulk_uintptr)(*(void**)&DAT_0052a17c);
    }
    (*(void**)&DAT_0052a17c) = node;
    node[0] = 0;
    leaveFn(((char*)&DAT_0052a188));
}