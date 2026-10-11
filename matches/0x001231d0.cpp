extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete[](void*);
struct T1 {
    char c;
    void Fini();
};
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
    char pad4[0x4c];
    void* m50;
    void* m54;
    char pad58[0x24];
    void* m7c;
    Ref* m80;
    Ref* m84;
    char pad88[4];
    void* m8c;
    void* m90;
    char pad94[0x2c];
    T1 mc0;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    if (m80) {
        m80->Release();
        m80 = 0;
    }
    if (m7c)
        m7c = 0;
    mc0.Fini();
    void* p = m8c;
    m90 = p;
    if (p)
        operator delete[](p);
    p = m50;
    m54 = p;
    if (p)
        operator delete[](p);
    Fin();
}
