// FUN_00223800 @ 0x00223800
#include "compat/ptr.h"
struct Elem_223800 {
    int w[10];
};

void __cdecl FUN_002234d0(Elem_223800 *first, int index, hulk_intptr count, Elem_223800 value);

void FUN_00223800(Elem_223800 *first, Elem_223800 *last)
{
    Elem_223800 tmp = last[-1];
    last[-1] = *first;
    FUN_002234d0(first, 0, (last - 1) - first, tmp);
}
