extern "C" void _ReadWriteBarrier();
extern void* g_vftable_175db0[];
class Ref_175db0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_175db0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_175db0 {
    char c;
};
void __fastcall SubFini(Sub_175db0*) throw();
void __fastcall SubFini2(Sub_175db0*) throw();
class Obj_175db0 : public Base_175db0 {
  public:
    char p1c[24];
    void* m1c;
    Ref_175db0* m20;
    char p28[4];
    Sub_175db0 s28;
    char p30[7];
    Ref_175db0* m30;
    ~Obj_175db0() throw();
};
Obj_175db0::~Obj_175db0() throw() {
    vptr = g_vftable_175db0;
    _ReadWriteBarrier();
    if (m30) {
        m30->Release();
        m30 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    SubFini(&s28);
    Fin();
}
