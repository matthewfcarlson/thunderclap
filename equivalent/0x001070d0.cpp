// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CRangedAgent::vfunc_7 @ 0x001070d0
struct RngResource {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void *vfunc_6(const char *, int);
};
struct CRangedAgent {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(char);
    virtual void vfunc_8(void *);
    char pad[0x54]; RngResource *resource;
};
void CRangedAgent::vfunc_7(char enabled) {
    if (enabled)
        vfunc_8(resource->vfunc_6("Rng", -1));
}
