// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 4/4)
// FUN_001f4940 @ 0x001f4940
#include "gen/owners.h"
extern char __cdecl FUN_00249b40(void *);
extern void __cdecl FUN_0024a800(void *, int);
extern "C" void __cdecl FUN_00240bb0();
extern void __cdecl FUN_002656a0();
void owners::Thing_1f4940::FUN_001f4940() {
    while (handle && !FUN_00249b40(handle)) {
        FUN_0024a800(handle, 10);
        FUN_00240bb0();
        FUN_002656a0();
    }
}