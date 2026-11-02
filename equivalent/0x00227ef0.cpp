// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00227ef0 @ 0x00227ef0
#include "compat/ptr.h"
struct Elem_227ef0 { int x, y, z; };
void __cdecl FUN_002273d0(Elem_227ef0 *first, int hole, hulk_intptr len, Elem_227ef0 value);

// Heap-sort phase: repeatedly moves the root to the back and re-sifts.
extern "C" void __cdecl FUN_00227ef0(void *first, void * last_)
{
    Elem_227ef0 * last = (Elem_227ef0 *)last_;
    while (last - ((Elem_227ef0 *)first) > 1) {
        --last;
        Elem_227ef0 value = *last;
        *last = *((Elem_227ef0 *)first);
        FUN_002273d0(((Elem_227ef0 *)first), 0, last - ((Elem_227ef0 *)first), value);
    }
}
