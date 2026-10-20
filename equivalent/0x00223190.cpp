// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 17/18, incomplete)
// FUN_00223190 @ 0x00223190
#include "compat/ptr.h"
struct Item_223190 { unsigned int words[10]; };
void __cdecl FUN_00223190(Item_223190* first, Item_223190* middle, Item_223190* last) {
    hulk_intptr shift = middle - first;
    hulk_intptr count = last - first;
    hulk_intptr a = count, b = shift;
    while (b != 0) { hulk_intptr r = a % b; a = b; b = r; }
    if (a >= count || a <= 0) return;
    Item_223190* start = first + a;
    for (hulk_intptr cycles = a; cycles != 0; --cycles, --start) {
        Item_223190 saved = *start;
        Item_223190* dest = start;
        Item_223190* next = start + shift;
        if (next == last) next = first;
        while (next != start) {
            *dest = *next;
            dest = next;
            hulk_intptr remaining = last - next;
            if (shift < remaining) next += shift;
            else next = first + (shift - remaining);
        }
        *dest = saved;
    }
}
