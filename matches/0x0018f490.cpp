// Same code shape as 0x0015cb40 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct Sub1_18f490;
struct Sub2_18f490;
struct Mid_18f490 {
    Sub1_18f490* A();
    Sub2_18f490* B();
};
struct Mgr_18f490 {
    Mid_18f490* Get();
};
struct Sub1_18f490 {
    void Init(int a, int b);
};
struct Sub2_18f490 {
    void Fin(int a);
};

void hulkfight::motion::TankLocomotionAction::vfunc_4() {
    Mid_18f490* m = (*(Mgr_18f490 * *)&this->f_20)->Get();
    Sub1_18f490* s = m->A();
    if (s) {
        s->Init(this->f_24, 0);
        Sub2_18f490* t = m->B();
        if (t)
            t->Fin(0);
    }
}
