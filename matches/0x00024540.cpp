#include "gen/owners.h"
bool owners::Obj_24540::FUN_00024540(hulk_intptr x) {
    int i = Lookup(((int)x));
    if (i == -1)
        return false;
    return values[i] == 1;
}