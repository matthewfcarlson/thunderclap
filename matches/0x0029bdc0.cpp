extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
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
    char pad[0xc];
    unsigned m10;
    char pad1[4];
    Ref* m18;
    Ref** m1c;
    char pad2[8];
    void* m28;
    void Clear();
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    Clear();
    for (unsigned i = 0; i < m10; i++) {
        Ref** p = &m1c[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m28)
        operator delete(m28);
    if (m1c)
        operator delete(m1c);
    Fin();
}
