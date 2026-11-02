// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00229ea0 @ 0x00229ea0
#include "compat/ptr.h"
struct Elem_229ea0 { int x, y, z; };
void __cdecl FUN_00229630(Elem_229ea0 *first, int hole, hulk_intptr len, Elem_229ea0 value);

// Heap-sort phase: repeatedly moves the root to the back and re-sifts.
extern "C" void __cdecl FUN_00229ea0(void *first, void * last_)
{
    Elem_229ea0 * last = (Elem_229ea0 *)last_;
    while (last - ((Elem_229ea0 *)first) > 1) {
        --last;
        Elem_229ea0 value = *last;
        *last = *((Elem_229ea0 *)first);
        FUN_00229630(((Elem_229ea0 *)first), 0, last - ((Elem_229ea0 *)first), value);
    }
}
