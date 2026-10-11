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
    char pad[0x14c];
    Ref* m150;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m150) {
        m150->Release();
        m150 = 0;
    }
    Fin();
}
