#include "compat/ptr.h"
#include "gen/physics.h"
extern "C" char DAT_004313cc[];
struct Part_2f2e70 {
    void Init();
};
struct CollisionCylinder_nv_2f2e70 {
    void Finish();
};
struct CollisionCylinder_2f2e70 {
    void* vptr;
    char pad[0x60];
    void Target();
};
void CollisionCylinder_2f2e70::Target() {
    vptr = (void*)((hulk_intptr)DAT_004313cc);
    ((Part_2f2e70*)((char*)this + 0x64))->Init();
    ((Part_2f2e70*)((char*)this + 0x38))->Init();
    ((CollisionCylinder_nv_2f2e70*)(((physics::CollisionCylinder*)(((physics::CollisionCylinder*)this)))))->Finish();
}