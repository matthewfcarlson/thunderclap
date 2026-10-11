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
    char pad[12];
    Ref* m;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
