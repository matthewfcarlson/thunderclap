extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_base_vftable[];
class Ref {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class A {
  public:
    void* vptr;
    char p[0x10];
    Ref* m14;
    Ref* m18;
    A* f2(unsigned char flags);
};
void operator delete(void*);
A* A::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m14) {
        m14->f1();
        m14 = 0;
    }
    if (m18) {
        m18->f1();
        m18 = 0;
    }
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
