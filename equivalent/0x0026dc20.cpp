// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 1/1)
// FUN_0026dc20 @ 0x0026dc20
// equiv-dead: +0x7 not taken: the null-result path dereferences null (faults on every input)
// The start routine of the fibers 0x0026dd10 creates: the calling thread's current fiber runs its entry.
#include "decls/data/records.h"

CoreThread* __cdecl FUN_0026dbb0();

void __stdcall FUN_0026dc20(int unused)
{
    CoreThread* t = FUN_0026dbb0();
    CoreFiber* o;
    if (t != 0) {
        o = t->current;
        o->state[0] = 0;
    } else {
        // the original dereferences the null result here (faults); kept as is
        o = (CoreFiber*)t;
        o->state[0] = 0;
    }
    o->entry(o->argument);
}
