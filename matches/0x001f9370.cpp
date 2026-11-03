#include "gen/owners.h"
typedef unsigned short ushort;
void owners::C_1f9370::FUN_001f9370(int param_2, char param_3) {
    if (param_3)
        *reinterpret_cast<ushort*>(this) |= (ushort)(1 << param_2);
    else
        *reinterpret_cast<ushort*>(this) &= (ushort) ~(1 << param_2);
}