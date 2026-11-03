#include "gen/owners.h"
bool owners::C_27cb80::FUN_0027cb80(void* p) {
    if (p && count < 1) {
        items[count] = p;
        ++count;
        return true;
    }
    return false;
}