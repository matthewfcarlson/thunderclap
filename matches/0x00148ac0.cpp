extern "C" void _ReadWriteBarrier();
extern void* g_vftable_148ac0[];
class Ref_148ac0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_148ac0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_148ac0 {
    char c;
};
void __fastcall SubFini(Sub_148ac0*) throw();
void __fastcall SubFini2(Sub_148ac0*) throw();
void __fastcall SubFini3(Sub_148ac0*) throw();
class Obj_148ac0 : public Base_148ac0 {
  public:
    char p1c[24];
    void* m1c;
    Ref_148ac0* m20;
    Sub_148ac0 s24;
    ~Obj_148ac0() throw();
};
Obj_148ac0::~Obj_148ac0() throw() {
    vptr = g_vftable_148ac0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    SubFini3(&s24);
    Fin();
}
