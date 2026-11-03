#include "gen/owners.h"
void owners::Obj_80c80::FUN_00080c80(char value) {
    if (value)
        flags |= 0x100;
    else
        flags &= 0xfffffeff;
}