#include "compat/ptr.h"
struct E_2277f0 {
    int x, y, z;
};
extern void __cdecl FUN_002273d0(E_2277f0* first, int hole, int len, E_2277f0 v);
void __cdecl FUN_002277f0(E_2277f0* first, E_2277f0* last) {
    hulk_intptr len = last - first;
    hulk_intptr parent = len / 2;
    while (parent > 0) {
        parent--;
        FUN_002273d0(first, parent, len, first[parent]);
    }
}
