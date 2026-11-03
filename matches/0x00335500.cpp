#include "gen/owners.h"
struct C_335500 {
    char pad[8];
    int type;
};
struct B_335500 {
    char pad[0x44];
    int count;
};
struct A_335500 {
    char pad[4];
    B_335500* b;
    unsigned int* values;
    bool run(int index, unsigned int* out);
};
bool A_335500::run(int index, unsigned int* out) {
    if (index < 0)
        return false;
    if (index >= b->count)
        return false;
    if (((C_335500 *)((owners::Thing_337090 *)b)->FUN_00337090(index))->type != 2)
        return false;
    *out = values[index];
    return true;
}