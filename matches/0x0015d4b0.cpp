extern "C" void _ReadWriteBarrier();
extern void* g_vftable_15d4b0[];
class Ref_15d4b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_15d4b0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_15d4b0 {
    char c;
};
void __fastcall SubFini(Sub_15d4b0*) throw();
void __fastcall SubFini2(Sub_15d4b0*) throw();
void __fastcall SubFini3(Sub_15d4b0*) throw();
class Obj_15d4b0 : public Base_15d4b0 {
  public:
    char p1c[24];
    Ref_15d4b0* m1c;
    Ref_15d4b0* m20;
    ~Obj_15d4b0() throw();
};
Obj_15d4b0::~Obj_15d4b0() throw() {
    vptr = g_vftable_15d4b0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
