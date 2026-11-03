#include "gen/owners.h"
typedef unsigned short ushort;
void owners::C_1f9370::FUN_001f9370(int bit, char set) {
    if (set)
        *reinterpret_cast<ushort*>(this) |= (ushort)(1 << bit);
    else
        *reinterpret_cast<ushort*>(this) &= (ushort) ~(1 << bit);
}