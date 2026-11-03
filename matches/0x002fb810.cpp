#include "gen/physics.h"
#include "gen/owners.h"

namespace physics {
} // namespace physics
struct Obj_2fb810 {
    char pad[256];
};
void physics::CollisionOBB::vfunc_11(void* __p0) { void * arg = (void *)__p0;

    Obj_2fb810* o = (Obj_2fb810*)arg;
    ((owners::M_22c3b0 *)o)->FUN_0022c3b0((float *)((char*)this + 0x54), (float *)((char*)this + 0x54));
    ((owners::M_22c3b0 *)o)->FUN_0022c3b0((float *)((char*)this + 0x60), (float *)((char*)this + 0x60));
    ((owners::M_22c3b0 *)o)->FUN_0022c3b0((float *)((char*)this + 0x6c), (float *)((char*)this + 0x6c));
    ((owners::Mat_22c2b0 *)o)->FUN_0022c2b0((float *)(hulk_uintptr)(int)(this->vfunc_4()), (float *)(hulk_uintptr)(int)(this->vfunc_4()));
}
