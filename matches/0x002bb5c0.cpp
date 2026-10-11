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
    char pad[0x10];
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
    vptr = g_vftable2;
}
