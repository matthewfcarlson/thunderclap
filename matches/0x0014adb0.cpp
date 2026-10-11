extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub {
  public:
    void Fn();
};
class Helper {
  public:
    void Fn();
};
class A {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref* m20;
    Sub m24;
    A* f2(unsigned char flags);
};
void operator delete(void*);
A* A::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    m24.Fn();
    ((Helper*)this)->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
