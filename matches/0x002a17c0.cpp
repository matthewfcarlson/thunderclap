extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
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
struct Sub {
    char c;
    void Fini();
};
class Obj : public Base {
  public:
    char pad[0x18 - 4];
    void* m18;
    int m1c;
    Sub sub;
    char pad2[0x2c - 0x21];
    Ref* m2c;
    char pad3[0x3c - 0x30];
    void* m3c;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m3c)
        operator delete(m3c);
    sub.Fini();
    m18 = g_vftable2;
    Fin();
}
