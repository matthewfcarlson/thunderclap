#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

typedef unsigned char u8;
struct Obj_10dee0 {
    char pad[0x14];
    u8 flag;
};
struct H {
    void f2();
    H* f3();
    void f4();
};
H* g();

bool hulkfight::ai::TokenSupressAction::vfunc_5(hulk_intptr a, int b) {
    if (!(*(H * *)&this->f_20))
        return false;
    ((H *)((owners::Object_592a0 *)((*(H * *)&this->f_20)))->FUN_000592a0())->f2();
    if ((*(Obj_10dee0 * *)&this->f_1c)->flag)
        g()->f4();
    return true;
}
