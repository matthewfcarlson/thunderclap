#include "compat/ptr.h"
#include "gen/owners.h"
struct Callee_b3d80 {
    void Yes(int);
};
struct Obj_b3d80 {
    char pad0[4];
    Callee_b3d80* p;
    char flag;
    void Run(hulk_intptr);
};
void Obj_b3d80::Run(hulk_intptr unused) {
    if (flag)
        p->Yes(unused);
    else
        ((owners::Obj_b3b50 *)p)->FUN_000b3b50(1);
}