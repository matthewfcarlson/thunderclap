extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1765a0[];
class Ref_1765a0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper_1765a0 {
  public:
    void Fn();
};
class SurfAction_1765a0 {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_1765a0* m20;
    Ref_1765a0* m24;
    void f();
};
void SurfAction_1765a0::f() {
    vptr = g_vftable_1765a0;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((Helper_1765a0*)this)->Fn();
}
