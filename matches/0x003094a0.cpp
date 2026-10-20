#include "compat/ptr.h"
#include "gen/physics.h"

extern "C" char DAT_00431d1c[];
typedef unsigned int u32_3094a0;
extern void* alloc(unsigned int);
struct Obj_3094a0 {
    void init();
};
struct HairclubPhysicsObject_nv_3094a0 {
    void build(void*, unsigned int);
};

void* physics::HairclubPhysicsObject::vfunc_28(unsigned int arg) {
    void* q = alloc(0x200);
    void* p;
    if (q) {
        p = q;
        ((Obj_3094a0*)p)->init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00431d1c);
        *(u32_3094a0*)((char*)p + 0x1f8) = 0;
        *(u32_3094a0*)((char*)p + 0x24) = 2;
    } else
        p = 0;
    ((HairclubPhysicsObject_nv_3094a0*)this)->build(p, arg);
    *(u32_3094a0*)((char*)p + 0x24) = *(u32_3094a0*)((char*)this + 0x24);
    return (void*)(p);
}
