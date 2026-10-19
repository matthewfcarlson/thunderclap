struct Vec {
    unsigned int x, y, z;
};
struct CLocator {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Vec* vfunc_8(Vec* out);
    virtual void vfunc_9();
    virtual void vfunc_10();
    char padding[12];
    Vec pos;
};
Vec* CLocator::vfunc_8(Vec* out) {
    *out = pos;
    return out;
}