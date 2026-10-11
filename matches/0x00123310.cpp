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
    char pad58[0x34];
    void* m8c;
    Ref* m90;
    Ref* m94;
    char pad98[4];
    void* m9c;
    void* ma0;
    char pada4[0x2c];
    T1 md0;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m94) {
        m94->Release();
        m94 = 0;
    }
    if (m90) {
        m90->Release();
        m90 = 0;
    }
    if (m8c)
        m8c = 0;
    md0.Fini();
    void* p = m9c;
    ma0 = p;
    if (p)
        operator delete[](p);
    p = m50;
    m54 = p;
    if (p)
        operator delete[](p);
    Fin();
}
