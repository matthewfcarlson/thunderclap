// STATUS: equivalent (tools/equiv.py level 3: 14508 inputs, branch coverage 2/2)
// FUN_0021fcb0 @ 0x0021fcb0
// FUN_0021fcb0 @ 0x0021fcb0
// FUN_0021fcb0 @ 0x0021fcb0
#include "compat/ptr.h"
struct Source { unsigned int value; };
struct Result { char pad0[0x14]; unsigned int data; char pad1[0x18]; int count; };
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char *, unsigned int, void *);
// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(Source *, const char *);
unsigned int __cdecl FUN_0021add0(unsigned int, int, int, int);
// equiv-conv: FUN_0021f940 eax ecx edx stack
extern "C" void __cdecl FUN_0021f940(unsigned int, unsigned char *, void *, unsigned int);
// equiv-conv: FUN_0021fcb0 eax ebx
extern "C" void FUN_0021fcb0(void *source, void *result) {
    int count;
    FUN_0021f8c0((char *)(int *)(&count), 4, (Source *)((Source *)source));
    if (count < 0) FUN_0021f800(((Source *)source), "bad integer");
    ((Result *)result)->data = FUN_0021add0(((Source *)source)->value, 0, 0, count * 4);
    ((Result *)result)->count = count;
    FUN_0021f940((int)count, (unsigned char *)(hulk_uintptr)(unsigned int)(((Result *)result)->data), (Source *)((Source *)source), 4);
}
