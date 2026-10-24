#include "gen/physics.h"

#include "compat/ptr.h"
extern int vtable_3103e0;
class Obj_3103e0 {
  public:
    virtual void Kill(int);
    virtual void Release();
};
extern void Free(void*);
struct ArticulatedPhysicsObject_nv_3103e0 {
    void Tail();
};

void physics::ArticulatedPhysicsObject::FUN_003103e0() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_3103e0;
    if ((*(Obj_3103e0 * *)&this->f_220))
        (*(Obj_3103e0 * *)&this->f_220)->Release();
    if ((*(Obj_3103e0 * *)&this->f_208))
        (*(Obj_3103e0 * *)&this->f_208)->Release();
    for (int i = 0; i < this->f_200; ++i) {
        Obj_3103e0* p = (*(Obj_3103e0 ** *)&this->f_1f8)[i];
        if (p)
            p->Kill(1);
    }
    Free((*(Obj_3103e0 ** *)&this->f_1f8));
    Free((*(void * *)&this->f_1fc));
    ((ArticulatedPhysicsObject_nv_3103e0*)this)->Tail();
}
