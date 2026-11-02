// STATUS: equivalent (tools/equiv.py level 3: 2199 inputs, branch coverage 2/2)
// FUN_002151e0 @ 0x002151e0
// FUN_002151e0 @ 0x002151e0
#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern "C" {
void __cdecl FUN_00219660(hulk_intptr, int);
unsigned int __cdecl FUN_002165c0(void *, int);
int __cdecl FUN_002152f0(hulk_intptr, void*, int);
// equiv-conv: FUN_00214f90 esi
void __cdecl FUN_00214f90(void *);
void __cdecl LAB_002151d0(void);
}
extern "C" void __cdecl FUN_002151e0(hulk_intptr param_1) {
    hulk_intptr esi = *(int*)(*(hulk_intptr*)(param_1 + 0x10) + 0x5c);
    FUN_00219660(esi, *(int*)(esi + 0x1c));
    FUN_002165c0((void *)(hulk_uintptr)(hulk_intptr)esi, 1);
    *(int*)(esi + 0x54) = 0;
    int r;
    do {
        hulk_intptr eax = *(int*)(esi + 0x28);
        *(hulk_intptr*)(esi + 0x14) = eax;
        eax = *(int*)eax;
        *(hulk_intptr*)(esi + 8) = eax;
        *(hulk_intptr*)(esi + 0xc) = eax;
        *(short*)(esi + 0x2e) = 0;
        r = FUN_002152f0(esi, (void*)LAB_002151d0, 0);
    } while (r != 0);
    FUN_00214f90((void *)(hulk_uintptr)(hulk_intptr)esi);
    _ReadWriteBarrier();
}
