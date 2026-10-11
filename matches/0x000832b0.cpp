extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
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
    char pad[0x3c - 4];
    Ref* m3c;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    Fin();
}
