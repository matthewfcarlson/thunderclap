#include "gen/owners.h"
extern int gFlags_329d50;
extern int gValues_329d50[];
void owners::Obj_329d50::FUN_00329d50(int index, int a, int b, int value) {
    helper(index, a, b);
    if (slots[index] != value) {
        slots[index] = value;
        gFlags_329d50 |= 0x800;
        gValues_329d50[index * 32] = value;
    }
}