#include "compat/ptr.h"
extern "C" void* alloc(hulk_uintptr);
extern "C" void init();
extern int* gA_292410;
extern int* gB_292410;
int* target() {
    if (gA_292410 == 0) {
        int* p = (int*)alloc(4);
        if (p != 0)
            *p = 0;
        else
            p = 0;
        gA_292410 = p;
        gB_292410 = p;
        init();
    }
    return gA_292410;
}