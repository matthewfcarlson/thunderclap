extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
};
class Obj : public Base {
  public:
    char pad[0x14];
    Ref* m18;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    vptr = g_vftable2;
}
