extern "C" void _ReadWriteBarrier();
extern void* g_vftable_ef400[];
extern void* g_vftable2[];
class Ref_ef400 {
  public:
    virtual void F0();
    virtual void Release();
};
class Del_ef400 {
  public:
    virtual void D(int);
};
class FEContainer_ef400 {
  public:
    void* vptr;
    void Fin();
};
class FEScreenBase_ef400 : public FEContainer_ef400 {
  public:
    char p[0x98c];
    Ref_ef400* m990;
    Ref_ef400* a[4];
    Ref_ef400* b[4];
    Ref_ef400* c[4];
    Ref_ef400* d[6];
    void* hvptr;
    char pad[4];
    Del_ef400* e[32];
    ~FEScreenBase_ef400() throw();
};
FEScreenBase_ef400::~FEScreenBase_ef400() throw() {
    *(void* volatile*)&vptr = g_vftable_ef400;
    Ref_ef400* t = *(Ref_ef400* volatile*)&m990;
    if (t) {
        t->Release();
        m990 = 0;
    }
    for (int i = 0; i < 4; i++)
        if (a[i]) {
            a[i]->Release();
            a[i] = 0;
        }
    for (int i = 0; i < 4; i++)
        if (b[i]) {
            b[i]->Release();
            b[i] = 0;
        }
    for (int i = 0; i < 4; i++)
        if (c[i]) {
            c[i]->Release();
            c[i] = 0;
        }
    for (int i = 0; i < 6; i++)
        if (d[i]) {
            d[i]->Release();
            d[i] = 0;
        }
    hvptr = g_vftable2;
    _ReadWriteBarrier();
    for (int i = 0; i < 32; i++)
        if (e[i]) {
            e[i]->D(1);
            e[i] = 0;
        }
    Fin();
}
