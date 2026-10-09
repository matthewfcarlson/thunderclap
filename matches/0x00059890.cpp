class Res {
  public:
    virtual void f0();
    virtual void Release();
};

extern int gVftable;
void __cdecl MyDelete(void*);

class CFightParams {
  public:
    void BaseCall();
    CFightParams* vfunc_2(unsigned char flag);
};

CFightParams* CFightParams::vfunc_2(unsigned char flag) {
    volatile void** vp = (volatile void**)this;
    *vp = (void**)&gVftable;
    volatile Res** dp = (volatile Res**)((char*)this + 0x10);
    Res* d = (Res*)*dp;
    if (d) {
        d->Release();
        *dp = 0;
    }
    volatile Res** cp = (volatile Res**)((char*)this + 0xc);
    Res* c = (Res*)*cp;
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
