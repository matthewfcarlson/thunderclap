extern "C" void _ReadWriteBarrier();
extern void* g_vftable_ef8f0[];
class Ref_ef8f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEScreenBase_ef8f0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_ef8f0 {
    char c;
};
void __fastcall SubFini(Sub_ef8f0*) throw();
void __fastcall SubFini2(Sub_ef8f0*) throw();
void __fastcall SubFini3(Sub_ef8f0*) throw();
class FEMenuBase_ef8f0 : public FEScreenBase_ef8f0 {
  public:
    char p990[2444];
    Ref_ef8f0* m990;
    ~FEMenuBase_ef8f0() throw();
};
FEMenuBase_ef8f0::~FEMenuBase_ef8f0() throw() {
    vptr = g_vftable_ef8f0;
    _ReadWriteBarrier();
    if (m990) {
        m990->Release();
        m990 = 0;
    }
    Fin();
}
