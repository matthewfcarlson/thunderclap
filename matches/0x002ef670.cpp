#include "gen/physics.h"
#include "compat/ptr.h"

extern "C" void* memcpy(void*, const void*, unsigned int);
struct SimState_nv_2ef670 {
    void update(void*, void*);
};

void physics::SimState::vfunc_12(void* __p0, float dt, bool apply) { float * delta = (float *)__p0;

    if (!(*(void * *)&this->f_70) || this->f_6c != 1)
        return;
    float temp[16];
    memcpy(temp, (char*)this + 0x10, 64);
    this->f_40 += delta[0];
    this->f_44 += delta[1];
    this->f_48 += delta[2];
    ((SimState_nv_2ef670*)this)->update(temp, (char*)this + 0x10);
    if (apply) {
        hulk_freg s = 1.0f / dt;
        *(float*)((char*)this + 0x50) += s * delta[0];
        *(float*)((char*)this + 0x54) += s * delta[1];
        *(float*)((char*)this + 0x58) += s * delta[2];
    }
}
