extern "C" void _ReadWriteBarrier();
extern void* g_a[];
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
    char pad[0x18];
    void* m1c;
    Ref* m20;
    void f();
};
void Obj::f() {
    vptr = g_a;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
