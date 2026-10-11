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
    char pad_3c[0x1c];
    Ref* m3c;
    char pad_48[0x8];
    Ref* m48;
    ~Obj();
};
Obj::~Obj() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    vptr = gA;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
