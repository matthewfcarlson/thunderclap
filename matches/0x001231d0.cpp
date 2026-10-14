extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1231d0[];
void operator delete[](void*);
struct T1 {
    char c;
    void Fini();
};
class Ref_1231d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1231d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1231d0 : public Base_1231d0 {
  public:
    char pad4[0x4c];
    void* m50;
    void* m54;
    char pad58[0x24];
    void* m7c;
    Ref_1231d0* m80;
    Ref_1231d0* m84;
    char pad88[4];
    void* m8c;
    void* m90;
    char pad94[0x2c];
    T1 mc0;
    ~Obj_1231d0() throw();
};
Obj_1231d0::~Obj_1231d0() throw() {
    vptr = g_vftable_1231d0;
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
