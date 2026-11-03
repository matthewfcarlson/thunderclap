#include "gen/hulkfight.h"
#include "gen/fight.h"

extern "C" void _ReadWriteBarrier();
extern char vtable_190a00[];
class Obj_190a00 {
  public:
    virtual void A();
    virtual void B();
};
class TankLocomotionAction_190a00 {
  public:
};

void hulkfight::motion::ImpulseVelocityAction::FUN_00190a00() {
    *(void**)this = &vtable_190a00;
    _ReadWriteBarrier();
    if ((*(Obj_190a00 * *)&this->f_20)) {
        (*(Obj_190a00 * *)&this->f_20)->B();
        (*(Obj_190a00 * *)&this->f_20) = 0;
    }
    if ((*(void * *)&this->f_1c))
        (*(void * *)&this->f_1c) = 0;
    ((fight::Action *)(((TankLocomotionAction_190a00*)this)))->FUN_002326a0();
}
