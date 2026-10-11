extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_base[];
void operator delete(void*);
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
    char pad[0x18];
    unsigned m1c;
    char pad2[0x08];
    Ref* m28;
    Ref** m2c;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < m1c; i++) {
        Ref** p = &m2c[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m2c)
        operator delete(m2c);
    vptr = g_base;
    Fin();
}
