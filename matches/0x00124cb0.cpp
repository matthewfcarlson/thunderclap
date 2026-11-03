#include "gen/hulkfight.h"
#include "gen/owners.h"

struct B_124cb0 {
    int h();
    void j();
};
struct A_124cb0 {
    B_124cb0* g();
};

void hulkfight::ai::ClearProjectileDistanceAction::vfunc_4() {
    B_124cb0* x = ((A_124cb0 *)((owners::Object_592a0 *)((*(A_124cb0 * *)&this->f_20)))->FUN_000592a0())->g();
    if (x->h())
        x->j();
}
