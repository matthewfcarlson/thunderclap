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
    char p34[48];
    void* m34;
    Ref* m38;
    Ref* m3c;
    char p60[32];
    Sub s60;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    if (m38) {
        m38->Release();
        m38 = 0;
    }
    if (m34)
        m34 = 0;
    SubFini(&s60);
    Fin();
}
