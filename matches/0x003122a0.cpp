#include "gen/physics.h"

extern "C" char DAT_0043217c[];
class Helper_3122a0 {
  public:
    void Init();
};
struct ArticulatedPhysicsObject_nv_3122a0 {
    void Setup(void*, unsigned int);
};
extern "C" void* __cdecl alloc(unsigned int);

void* physics::ArticulatedPhysicsObject::vfunc_28(unsigned int a) {
    void* p = alloc(0x238);
    if (p) {
        ((Helper_3122a0*)p)->Init();
        *(unsigned int*)p = ((int)DAT_0043217c);
        *(unsigned int*)((char*)p + 0x1fc) = 0;
        *(unsigned int*)((char*)p + 0x24) = 1;
    } else {
        p = 0;
    }
    ((ArticulatedPhysicsObject_nv_3122a0*)this)->Setup(p, a);
    *(unsigned int*)((char*)p + 0x24) = *(unsigned int*)((char*)this + 0x24);
    return (void*)((physics::ArticulatedPhysicsObject*)p);
}
