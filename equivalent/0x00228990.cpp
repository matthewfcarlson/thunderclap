// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_00228990 @ 0x00228990
#include "compat/ptr.h"
struct Item_228990 { unsigned int a, b, c; };
void __cdecl FUN_00228990(Item_228990* first, Item_228990* middle, Item_228990* last)
{
    hulk_intptr shift = middle - first;
    hulk_intptr count = last - first;
    hulk_intptr a = count;
    hulk_intptr b = shift;
    while (b != 0) {
        hulk_intptr remainder = a % b;
        a = b;
        b = remainder;
    }
    if (a >= count || a <= 0) return;
    Item_228990* start = first + a;
    for (hulk_intptr cycles = a; cycles != 0; --cycles, --start) {
        Item_228990 saved = *start;
        Item_228990* destination = start;
        Item_228990* source = start + shift;
        if (source == last) source = first;
        while (source != start) {
            destination->a = source->a;
            destination->b = source->b;
            destination->c = source->c;
            hulk_intptr remaining = last - source;
            destination = source;
            if (shift < remaining) source += shift;
            else source = first + (shift - remaining);
        }
        destination->a = saved.a;
        destination->b = saved.b;
        destination->c = saved.c;
    }
}
