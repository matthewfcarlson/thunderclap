extern "C" void _ReadWriteBarrier();
extern void* g_vftable_173460[];
class Ref_173460 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_173460 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_173460 {
    char c;
};
void __fastcall SubFini(Sub_173460*) throw();
void __fastcall SubFini2(Sub_173460*) throw();
class Obj_173460 : public Base_173460 {
  public:
    char p1c[24];
    void* m1c;
    Ref_173460* m20;
    Ref_173460* m24;
    char p74[76];
    Ref_173460* m74;
    ~Obj_173460() throw();
};
Obj_173460::~Obj_173460() throw() {
    vptr = g_vftable_173460;
    _ReadWriteBarrier();
    if (m74) {
        m74->Release();
        m74 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
