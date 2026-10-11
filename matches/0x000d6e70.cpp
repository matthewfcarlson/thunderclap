extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class A {
  public:
    void* vptr;
    Ref* m4;
    char p8[0x24];
    Ref* m2c;
    A* f2(unsigned char flags);
};
void operator delete(void*);
A* A::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m4) {
        m4->f1();
        m4 = 0;
    }
    if (m2c) {
        m2c->f1();
        m2c = 0;
    }
    if (flags & 1)
        operator delete(this);
    return this;
}
