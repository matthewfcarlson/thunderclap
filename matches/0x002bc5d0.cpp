extern void* g_vftable[];
extern "C" void _ReadWriteBarrier();
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
class Quad : public Base {
  public:
    char pad[0x80];
    Ref* m84;
    char pad2[4];
    Ref** b;
    Ref** e;
    ~Quad();
};
Quad::~Quad() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    for (unsigned i = 0; i < (unsigned)(e - b); i++) {
        Ref** p = &b[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (b)
        operator delete(b);
    Fin();
}
