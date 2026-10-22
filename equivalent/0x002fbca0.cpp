// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// physics::CollisionOBB::vfunc_9 @ 0x002fbca0
extern "C" double __cdecl sqrt(double);
namespace physics {
struct CollisionVolume {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
};
struct CollisionOBB : CollisionVolume {
    char padding[0x30];
    float radius;
    char padding2[0x10];
    float x;
    float y;
    float z;
    virtual void vfunc_9();
};
void CollisionOBB::vfunc_9() {
    radius = (float)sqrt(y*y + z*z + x*x);
    CollisionVolume::vfunc_9();
}
}
