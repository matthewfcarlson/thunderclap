extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
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
    char pad[24];
    Ref* m;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
