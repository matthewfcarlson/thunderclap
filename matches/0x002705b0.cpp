#include "compat/ptr.h"
typedef unsigned int uint_2705b0;
extern "C" void FUN_003479bc(uint_2705b0);
void FUN_002705b0(hulk_uintptr ptr) {
    if (ptr) {
        FUN_003479bc(*(uint_2705b0*)((char*)ptr - 4));
    }
}