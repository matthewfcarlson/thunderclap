extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA[];
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
    char pad_1c[0x18];
    Ref* m1c;
    char pad_28[0x8];
    Ref* m28;
    ~Obj();
};
Obj::~Obj() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    vptr = gA;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
