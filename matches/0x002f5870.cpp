#include "gen/physics.h"
#include "decls/data/game/global.h"
#include "compat/ptr.h"

extern "C" void _ReadWriteBarrier();
class Elem_2f5870 {
  public:
    void Fn(float);
};

void physics::PhysicsObject::vfunc_7() {
    if (this->f_3c > DAT_003f32e0) {
        float old = this->f_40;
        // x87: the reciprocal is taken of the product still in its register (53 bits), not of the stored f_40
        hulk_freg p = *(float*)((char*)this->f_18 + 0xc) * this->f_3c;
        ((Elem_2f5870*)((char*)this + 0xdc))
            ->Fn(((this->f_40 = p), (this->f_44 = DAT_003f32dc / p), *(volatile float*)&this->f_40) / old);
        vfunc_39();
        *((char*)this + 0x1c4) = 1;
    } else {
        this->f_40 = 0.0f;
        this->f_44 = 0.0f;
        *((char*)this + 0x1c4) = 1;
    }
}
