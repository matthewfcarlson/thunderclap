extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int);
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
class Obj : public Base {
  public:
    char pad[4];
    Sub sub;
    char p2[7];
    Ref* m10;
    Ref* m14;
    Ref* m18;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    if (m14)
        m14->V10(0);
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    SubFini(&sub);
    vptr = g_vftable2;
}
