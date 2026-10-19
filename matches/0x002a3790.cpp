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
    virtual int vfunc_18(int index);
};
struct ParticleSystem : DrawableContainer {
    char padding[0xa0];
    int particle;
    virtual int vfunc_18(int index);
};
int ParticleSystem::vfunc_18(int index) {
    if (particle) {
        if (index == 0)
            return particle;
        --index;
    }
    return DrawableContainer::vfunc_18(index);
}
} // namespace pure3d