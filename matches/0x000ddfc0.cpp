extern void* g_vftable[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Sub {
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad4[0x1824];
    Ref* m1828;
    char pad182c[0x2224 - 0x182c];
    Ref* m2224;
    char pad2228[8];
    Sub* m2230;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    Sub* p = m2230;
    vptr = g_vftable;
    if (p) {
        p->Fini();
        operator delete(p);
        m2230 = 0;
    }
    if (m2224) {
        m2224->Release();
        m2224 = 0;
    }
    if (m1828) {
        m1828->Release();
        m1828 = 0;
    }
    Fin();
}
