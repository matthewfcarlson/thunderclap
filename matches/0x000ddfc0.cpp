extern void* g_vftable_ddfc0[];
void operator delete(void*);
class Ref_ddfc0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Sub_ddfc0 {
    void Fini();
};
class FEThingsBase_ddfc0 {
  public:
    void* vptr;
    void Fin();
};
class FEThings_ddfc0 : public FEThingsBase_ddfc0 {
  public:
    char pad4[0x1824];
    Ref_ddfc0* m1828;
    char pad182c[0x2224 - 0x182c];
    Ref_ddfc0* m2224;
    char pad2228[8];
    Sub_ddfc0* m2230;
    ~FEThings_ddfc0() throw();
};
FEThings_ddfc0::~FEThings_ddfc0() throw() {
    Sub_ddfc0* p = m2230;
    vptr = g_vftable_ddfc0;
    if (p) {
        p->Fini();
        operator delete(p);
        m2230 = 0;
    }
    if (m2224) {
        m2224->Release();
        m2224 = 0;
    }
    if (m1828) {
        m1828->Release();
        m1828 = 0;
    }
    Fin();
}
