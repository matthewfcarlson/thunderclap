// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 4/4)
// FUN_00223d20 @ 0x00223d20
#include "compat/ptr.h"
struct Elem_223d20 {
    int w[10];
};

void __cdecl FUN_002234d0(Elem_223d20 *first, int index, hulk_intptr count, Elem_223d20 value);

extern "C" void FUN_00223d20(void *first, void * last_)
{
    Elem_223d20 * last = (Elem_223d20 *)last_;
    while (last - ((Elem_223d20 *)first) > 1) {
        --last;
        Elem_223d20 tmp = *last;
        *last = *((Elem_223d20 *)first);
        FUN_002234d0(((Elem_223d20 *)first), 0, last - ((Elem_223d20 *)first), tmp);
    }
}
