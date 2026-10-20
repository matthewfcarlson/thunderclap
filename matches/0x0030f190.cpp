// Same code shape as 0x00221cd0 (propagated; names are from that function)
#include "compat/ptr.h"
struct Sub_30f190 {
    char pad[0x10];
    void f(hulk_intptr);
};
struct C_30f190 {
    char pad[0x40];
    Sub_30f190 sub;
    int state;
    void* target();
};
void* C_30f190::target() {
    if (state == 2) {
        sub.f((hulk_intptr)this);
        state = 0;
    }
    return (void*)&sub;
}