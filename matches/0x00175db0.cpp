extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub {
    char c;
};
void __fastcall SubFini(Sub*) throw();
void __fastcall SubFini2(Sub*) throw();
class Obj : public Base {
  public:
    char p1c[24];
    void* m1c;
    Ref* m20;
    char p28[4];
    Sub s28;
    char p30[7];
    Ref* m30;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
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
