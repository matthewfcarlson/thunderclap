extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
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
class Obj : public Base {
  public:
    char p[0x18];
    Ref* m1c;
    Ref* m20;
    Ref* m24;
    char p2[0x20];
    void* m48;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m48)
        m48 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
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
