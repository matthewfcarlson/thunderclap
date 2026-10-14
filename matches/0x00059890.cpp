class Res_59890 {
  public:
    virtual void f0();
    virtual void Release();
};

extern int gVftable_59890;
void __cdecl MyDelete(void*);

class CFightParams {
  public:
    void BaseCall();
    CFightParams* vfunc_2(unsigned char flag);
};

CFightParams* CFightParams::vfunc_2(unsigned char flag) {
    volatile void** vp = (volatile void**)this;
    *vp = (void**)&gVftable_59890;
    volatile Res_59890** dp = (volatile Res_59890**)((char*)this + 0x10);
    Res_59890* d = (Res_59890*)*dp;
    if (d) {
        d->Release();
        *dp = 0;
    }
    volatile Res_59890** cp = (volatile Res_59890**)((char*)this + 0xc);
    Res_59890* c = (Res_59890*)*cp;
    if (c) {
        c->Release();
        *cp = 0;
    }
    BaseCall();
    if (flag & 1) {
        MyDelete(this);
    }
    return this;
}
