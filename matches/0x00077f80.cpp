class CHeliDeathSpiralTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual unsigned int vfunc_12(unsigned int);
    virtual void v13();
};
extern void* __cdecl FUN_0008d690(unsigned int);
struct Helper_77f80 {
    unsigned int call(CHeliDeathSpiralTrack*, unsigned int);
};
unsigned int CHeliDeathSpiralTrack::vfunc_12(unsigned int x) {
    void* p = FUN_0008d690(0x48);
    if (p)
        return ((Helper_77f80*)p)->call(this, x);
    return 0;
}