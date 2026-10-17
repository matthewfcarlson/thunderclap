// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticleSystem::vfunc_18 @ 0x002a3790
namespace pure3d {
struct DrawableContainer {
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int index);
};
struct ParticleSystem : DrawableContainer {
    char padding[0xa0];
    int particle;
    virtual void vfunc_18(int index);
};
void ParticleSystem::vfunc_18(int index) {
    if (particle) {
        if (index == 0) return;
        --index;
    }
    DrawableContainer::vfunc_18(index);
}
}