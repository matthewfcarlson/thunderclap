// STATUS: equivalent (tools/equiv.py level 3: 14802 inputs, branch coverage 4/4)
// physics::CollisionVolume::vfunc_12 @ 0x003068a0
// physics::CollisionVolume::vfunc_12 @ 0x003068a0
namespace physics {
struct CollisionVolume {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(CollisionVolume*, void*);
    char pad[0x15];
    unsigned char dirty;
};
}
// equiv-conv: FUN_00306790 eax ebx stack
void __cdecl FUN_00306790(physics::CollisionVolume*, physics::CollisionVolume*, void*);
void physics::CollisionVolume::vfunc_12(CollisionVolume* other, void* arg) {
    if (!dirty) vfunc_10();
    if (!other->dirty) other->vfunc_10();
    FUN_00306790(this, other, arg);
}
