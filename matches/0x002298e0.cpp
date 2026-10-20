#include "compat/ptr.h"
struct E_2298e0 {
    int x, y, z;
};
extern void __cdecl FUN_00229630(E_2298e0* first, int hole, int len, E_2298e0 v);
void __cdecl FUN_002298e0(E_2298e0* first, E_2298e0* last) {
    hulk_intptr len = last - first;
    hulk_intptr parent = len / 2;
    while (parent > 0) {
        parent--;
        FUN_00229630(first, parent, len, first[parent]);
    }
}
