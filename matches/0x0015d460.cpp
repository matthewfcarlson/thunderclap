#include "gen/hulkfight.h"

#include "compat/ptr.h"
class Ref_15d460 {
  public:
    virtual void A();
    virtual void B();
};
extern int vtable_15d460;
struct Action_15d460 {
    void InitBase();
};
struct LocomotionStrafeAction_nv_15d460 {
    void InitBase();
};

hulkfight::motion::LocomotionStrafeAction* hulkfight::motion::LocomotionStrafeAction::FUN_0015d460(void* __p0) { Ref_15d460 * p = (Ref_15d460 *)__p0;

    ((LocomotionStrafeAction_nv_15d460*)this)->InitBase();
    *(hulk_intptr*)this = (hulk_intptr)&vtable_15d460;
    (*(Ref_15d460 * *)&this->f_1c) = 0;
    (*(int *)&this->f_20) = 0;
    if (p)
        p->A();
    if ((*(Ref_15d460 * *)&this->f_1c))
        (*(Ref_15d460 * *)&this->f_1c)->B();
    (*(Ref_15d460 * *)&this->f_1c) = p;
    return (hulkfight::motion::LocomotionStrafeAction*)(this);
}
