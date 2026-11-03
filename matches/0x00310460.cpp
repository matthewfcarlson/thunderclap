#include "gen/owners.h"
bool owners::C_310460::FUN_00310460(int index, char value) {
    char* p = (char*)arr[index];
    if (p && p[4] != value)
        p[4] = value;
    return false;
}