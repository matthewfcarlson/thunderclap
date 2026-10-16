#include "gen/core.h"

void core::ControllerInputPointXBox::vfunc_7(int a, int b) {
    if (*(int*)((char*)this + 0x2c) == 0) {
        *(int*)((char*)this + 0x30) = b;
        *(int*)((char*)this + 0x2c) = a;
    }
}
