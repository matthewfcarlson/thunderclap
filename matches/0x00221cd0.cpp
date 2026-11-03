#include "compat/ptr.h"
#include "gen/owners.h"
struct Sub_221cd0 {
    char pad[0x10];
};
struct C_221cd0 {
    char pad[0x40];
    Sub_221cd0 sub;
    int state;
    void* target();
};
void* C_221cd0::target() {
    if (state == 2) {
        ((owners::Quat_22b370 *)&sub)->FUN_0022b370((const float *)(hulk_uintptr)(hulk_intptr)((hulk_intptr)this));
        state = 0;
    }
    return (void*)&sub;
}