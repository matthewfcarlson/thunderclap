#include "gen/physics.h"

namespace physics {
} // namespace physics
struct Obj_2fb810 {
    char pad[256];
    void cp(void*, void*);
    void end(int, int);
};
void physics::CollisionOBB::vfunc_11(void* __p0) { void * arg = (void *)__p0;

    Obj_2fb810* o = (Obj_2fb810*)arg;
    o->cp((char*)this + 0x54, (char*)this + 0x54);
    o->cp((char*)this + 0x60, (char*)this + 0x60);
    o->cp((char*)this + 0x6c, (char*)this + 0x6c);
    o->end(this->vfunc_4(), this->vfunc_4());
}
