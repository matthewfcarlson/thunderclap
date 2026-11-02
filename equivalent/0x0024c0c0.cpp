// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0024c0c0 @ 0x0024c0c0
#include "compat/ptr.h"
struct Stream {
    char pad0[8];
    int handle;
    char pad0c[0xb4];
    int state;
    int status;
};

extern "C" void * __cdecl FUN_00259c50(void *);
void __cdecl FUN_00258e50(int handle);
// equiv-conv: FUN_0024bc70 eax
extern "C" void __cdecl FUN_0024bc70(void *);

extern "C" void __cdecl FUN_0024c0c0(Stream* s)
{
    if (s->state == 0 || s->state == 5)
        return;
    if (s->state == 2) {
        if (((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(s->handle))) == 1)
            FUN_00258e50(s->handle);
    }
    s->state = 5;
    do {
        FUN_0024bc70((Stream *)s);
    } while (s->status == 3);
}
