// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 4/4)
// FUN_00223760 @ 0x00223760
#include "compat/ptr.h"
struct Elem_223760 {
    int w[10];
};

void __cdecl FUN_002234d0(Elem_223760 *first, int index, int count, Elem_223760 value);

void FUN_00223760(Elem_223760 *first, Elem_223760 *last)
{
    hulk_intptr n = last - first;
    hulk_intptr i = n / 2;
    last = first + i;
    while (i > 0) {
        --last;
        --i;
        FUN_002234d0(first, i, n, *last);
    }
}
