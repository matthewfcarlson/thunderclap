#include "compat/ptr.h"
extern "C" char hulk_at_0049b894[];
extern "C" int g_x;
extern "C" void __stdcall FUN_00079390(int x) {
    *(int*)((hulk_intptr)hulk_at_0049b894) = x;
}
