// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 6/6)
// physics::CollisionVolume::vfunc_7 @ 0x00306560
namespace physics {
struct CollisionVolume;
struct ChildList { CollisionVolume **begin; CollisionVolume **end; };
struct CollisionVolume {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(void *value);
    char pad[0x10];
    ChildList *children;
    void FUN_00306560(void *value);
};
void CollisionVolume::FUN_00306560(void *value) {
    if (children) {
        for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); ++i)
            children->begin[i]->vfunc_7(value);
    }
}
}