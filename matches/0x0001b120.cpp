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
    char pad_24[0x4];
    Ref* m24;
    char pad_7c[0x54];
    Ref* m7c;
    ~Obj();
};
Obj::~Obj() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m7c) {
        m7c->Release();
        m7c = 0;
    }
    vptr = gA;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
