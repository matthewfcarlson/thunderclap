extern "C" void _ReadWriteBarrier();
extern void* g_vftable_123310[];
void operator delete[](void*);
struct T1 {
    char c;
    void Fini();
};
class Ref_123310 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_123310 {
  public:
    void* vptr;
    void Fin();
};
class Obj_123310 : public Base_123310 {
  public:
    char pad4[0x4c];
    void* m50;
    void* m54;
    char pad58[0x34];
    void* m8c;
    Ref_123310* m90;
    Ref_123310* m94;
    char pad98[4];
    void* m9c;
    void* ma0;
    char pada4[0x2c];
    T1 md0;
    ~Obj_123310() throw();
};
Obj_123310::~Obj_123310() throw() {
    vptr = g_vftable_123310;
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
