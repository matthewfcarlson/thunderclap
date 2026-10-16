#include "gen/hulkfight.h"

struct B_124cb0 {
    int h();
    void j();
};
struct A_124cb0 {
    A_124cb0* f();
    B_124cb0* g();
};

void hulkfight::ai::ClearProjectileDistanceAction::vfunc_4() {
    B_124cb0* x = (*(A_124cb0 * *)&this->f_20)->f()->g();
    if (x->h())
        x->j();
}
