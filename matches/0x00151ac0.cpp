#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Obj_151ac0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Obj_151ac0* get();
    void* helper1();
    Obj_151ac0* helper2();
    void send(void*, float*);
};

bool hulkfight::motion::HitPushbackAddAction::vfunc_3(hulk_intptr __p0, hulk_intptr x) { Obj_151ac0 * arg = (Obj_151ac0 *)__p0;

    if ((*(Obj_151ac0 * *)&this->f_20)) {
        Obj_151ac0* p = (*(Obj_151ac0 * *)&this->f_20)->get();
        if (p) {
            Obj_151ac0* a = (Obj_151ac0*)(*(Obj_151ac0 * *)&this->f_20)->helper1();
            Obj_151ac0* b = a->helper2();
            float t = *(float*)((char*)(*(Obj_151ac0 * *)&this->f_1c) + 0x10);
            float* v = (float*)((char*)p + 0x28);
            float out[3];
            out[0] = t * v[0];
            out[1] = t * v[1];
            out[2] = t * v[2];
            b->send(*(void**)((char*)p + 0x5c), out);
        }
    }
    return false;
}
