extern "C" void _ReadWriteBarrier();
extern void* g_vftable_29bdc0[];
void operator delete(void*);
class Ref_29bdc0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_29bdc0 {
  public:
    void* vptr;
    void Fin();
};
class DisplayList_29bdc0 : public Entity_29bdc0 {
  public:
    char pad[0xc];
    unsigned m10;
    char pad1[4];
    Ref_29bdc0* m18;
    Ref_29bdc0** m1c;
    char pad2[8];
    void* m28;
    void Clear();
    ~DisplayList_29bdc0() throw();
};
DisplayList_29bdc0::~DisplayList_29bdc0() throw() {
    vptr = g_vftable_29bdc0;
    _ReadWriteBarrier();
    Clear();
    for (unsigned i = 0; i < m10; i++) {
        Ref_29bdc0** p = &m1c[i];
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
