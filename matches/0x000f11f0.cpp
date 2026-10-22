extern "C" void _ReadWriteBarrier();
extern void* g_vftable_f11f0[];
class Ref_f11f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEPoseAnimation_f11f0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_f11f0 {
    char c;
};
void __fastcall SubFini(Sub_f11f0*) throw();
void __fastcall SubFini2(Sub_f11f0*) throw();
void __fastcall SubFini3(Sub_f11f0*) throw();
class FEParticleAnimation_f11f0 : public FEPoseAnimation_f11f0 {
  public:
    char p64[96];
    Ref_f11f0* m64;
    FEParticleAnimation_f11f0* f(unsigned char fl);
};
FEParticleAnimation_f11f0* FEParticleAnimation_f11f0::f(unsigned char fl) {
    vptr = g_vftable_f11f0;
    _ReadWriteBarrier();
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
