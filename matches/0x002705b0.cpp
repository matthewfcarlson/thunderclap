#include "compat/ptr.h"
typedef unsigned int uint_2705b0;
extern "C" void FUN_003479bc(uint_2705b0);
void FUN_002705b0(hulk_uintptr param_1) {
    if (param_1) {
        FUN_003479bc(*(uint_2705b0*)((char*)param_1 - 4));
    }
}