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
    Ref* m24;
    Ref* m28;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
