#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_135ba0 {
    void init();
    int check();
};
struct Result_135ba0 {
    void apply(int, int);
};
struct FlyingAttackAction_nv_135ba0 {
    void mid();
};

void hulkfight::motion::FlyingAttackAction::vfunc_4() {
    A_135ba0* edi = ((A_135ba0 *)((owners::Object_592a0 *)((*(A_135ba0 * *)&this->f_20)))->FUN_000592a0());
    edi->init();
    ((FlyingAttackAction_nv_135ba0*)this)->mid();
    hulk_intptr result = edi->check();
    if (result)
        ((Result_135ba0*)result)->apply(this->f_24, 0);
}
