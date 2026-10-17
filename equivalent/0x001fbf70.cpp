// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CLocator::vfunc_8 @ 0x001fbf70
struct CLocator {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(unsigned int *out);
    virtual void vfunc_9();
    virtual void vfunc_10();
    char padding[12];
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
void CLocator::vfunc_8(unsigned int *out) {
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
