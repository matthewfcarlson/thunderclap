extern "C" void _ReadWriteBarrier();
extern void* gA[];
extern void* gB[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct S {
    int a;
    void Fini();
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
    char pad2[4];
    S s18;
    ~Obj();
};
Obj::~Obj() {
    vptr = gA;
    s18.Fini();
    vptr = gB;
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
