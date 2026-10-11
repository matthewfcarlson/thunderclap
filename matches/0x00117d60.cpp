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
void __fastcall SubFini3(Sub*) throw();
class Obj : public Base {
  public:
    char p1c[24];
    void* m1c;
    Ref* m20;
    char p60[60];
    Sub s60;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    SubFini(&s60);
    Fin();
}
