// Same code shape as 0x00221eb0 (propagated; names are from that function)
#include "gen/owners.h"
struct Sub_30f370 {
    void call(struct Obj_30f370*);
};
struct Obj_30f370 {
    char pad[0x40];
    Sub_30f370 sub;
    char pad2[0xc];
    int state;
    void target();
};
void Obj_30f370::target() {
    if (state == 1) {
        sub.call(this);
        state = 0;
    }
    ((owners::Matrix_22c120 *)this)->FUN_0022c120();
    state = 2;
}
