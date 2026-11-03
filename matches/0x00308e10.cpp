#include "gen/owners.h"
bool owners::C_308e10::FUN_00308e10(int index, unsigned char value) {
    bool result = false;
    if (index >= 0 && index < count) {
        items[index * 0x34 + 0x30] = value;
        result = true;
    }
    return result;
}