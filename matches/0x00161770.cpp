extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Helper {
  public:
    void Fn();
};
class A {
  public:
    void* vptr;
    char p[0x1c];
    Ref* m20;
    Ref* m24;
    A* f2(unsigned char flags);
};
void operator delete(void*);
A* A::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    m20->f1();
    ((Helper*)this)->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
