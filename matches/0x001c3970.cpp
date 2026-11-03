#include "gen/owners.h"
typedef unsigned int u32_1c3970;
extern "C" void* memcpy(void*, const void*, unsigned int);
void owners::Obj_1c3970::FUN_001c3970(u32_1c3970* src) {
    memcpy(data, src, 64);
    flag = 0;
}