extern "C" void _ReadWriteBarrier();
extern void* g_vftable_ef820[];
class Ref_ef820 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_ef820 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_ef820 {
    char c;
};
void __fastcall SubFini(Sub_ef820*) throw();
void __fastcall SubFini2(Sub_ef820*) throw();
void __fastcall SubFini3(Sub_ef820*) throw();
class Obj_ef820 : public Base_ef820 {
  public:
    char p9a4[2464];
    Ref_ef820* m9a4;
    ~Obj_ef820() throw();
};
Obj_ef820::~Obj_ef820() throw() {
    vptr = g_vftable_ef820;
    _ReadWriteBarrier();
    if (m9a4) {
        m9a4->Release();
        m9a4 = 0;
    }
    Fin();
}
