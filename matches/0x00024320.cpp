#include "gen/owners.h"
bool owners::ItemList_24320::FUN_00024320(int index) {
    if (index < 0 || index >= count)
        return false;
    --count;
    values[index] = 0;
    if (count > 0) {
        values[index] = values[count];
        values[count] = 0;
        field54[index] = field54[count];
        field94[index] = field94[count];
    }
    return true;
}