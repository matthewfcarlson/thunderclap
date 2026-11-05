#include "compat/ptr.h"
struct Dest_321da0 {
    int go(int, int, int, int);
};
struct Obj_321da0 {
    char pad[0x208];
    Dest_321da0* member;
    hulk_intptr target(hulk_intptr, int, int, int);
};
hulk_intptr Obj_321da0::target(hulk_intptr a0, int a1, int a2, int a3) {
    return member->go(a0, a1, a2, a3);
}