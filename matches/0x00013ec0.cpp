#include "gen/owners.h"
struct C_13ec0 {
    int second();
};
struct B_13ec0 {
};
struct Obj_13ec0 {
    char pad[0x1c];
    B_13ec0* member;
    int target();
};
int Obj_13ec0::target() {
    return ((C_13ec0 *)((owners::Object_592a0 *)member)->FUN_000592a0())->second();
}