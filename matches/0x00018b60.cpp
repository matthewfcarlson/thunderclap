extern "C" void _ReadWriteBarrier();
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
    char pad[0x1c - 4];
    Ref* m1c;
    ~Obj();
};
Obj::~Obj() {
    vptr = gA;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
