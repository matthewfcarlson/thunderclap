extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete(void*);
void operator delete[](void*);
class A {
  public:
    void* vptr;
    char p[0x14];
    int m18;
    int m1c;
    int m20;
    A* f(unsigned char flags);
};
A* A::f(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    volatile int old = m1c;
    int v = m20;
    m18 = v;
    m1c = v;
    if (v)
        operator delete[]((void*)v);
    if (flags & 1)
        operator delete(this);
    return this;
}
