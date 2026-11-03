#include "gen/owners.h"
extern "C" void* memcpy(void*, const void*, unsigned int);
void owners::Obj_31eb70::FUN_0031eb70(const owners::Obj_31eb70* s) {
    for (int i = 0; i < 8; i++)
        memcpy(block[i], s->block[i], 0x7c);
    tail[0] = s->tail[0];
    tail[1] = s->tail[1];
}