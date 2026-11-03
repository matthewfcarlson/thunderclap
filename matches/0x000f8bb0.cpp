#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* memset(void*, int, unsigned int);
owners::Obj_f8bb0* owners::Obj_f8bb0::FUN_000f8bb0(hulk_intptr a) {
    vptr = (void*)((hulk_intptr)a);
    memset(data, 0, 0x80 * 4);
    return this;
}
