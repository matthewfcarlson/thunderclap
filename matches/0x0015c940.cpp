#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Sub_15c940 {
    void setA(int a, int b, float c);
    void setB(int a, int b);
};
struct Child_15c940 {
    void doIt(int a);
};
struct Obj_15c940 {
    Sub_15c940* make();
    Child_15c940* child();
};
struct Mgr_15c940 {
};

namespace hulkfight {
namespace motion {

} // namespace motion
} // namespace hulkfight
void hulkfight::motion::ClimbLocomotionAction::vfunc_4() {
    if (this->f_20) {
        Obj_15c940* o = ((Obj_15c940 *)((owners::Object_592a0 *)((*(Mgr_15c940 * *)&this->f_1c)))->FUN_000592a0());
        Sub_15c940* s = o->make();
        if (s) {
            s->setA(this->f_20, 0, -1.0f);
            s->setB(this->f_24, 0);
            Child_15c940* c = o->child();
            if (c)
                c->doIt(0);
        }
    }
}
