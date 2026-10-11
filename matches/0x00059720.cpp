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
    char pad[0xc - 4];
    Ref* mc;
    Ref* m10;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    Fin();
}
