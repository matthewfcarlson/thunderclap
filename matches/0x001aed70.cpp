extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1aed70[];
void operator delete(void*);
void operator delete[](void*);
class A_1aed70 {
  public:
    void* vptr;
    char p[0x14];
    int m18;
    int m1c;
    int m20;
    A_1aed70* f(unsigned char flags);
};
A_1aed70* A_1aed70::f(unsigned char flags) {
    vptr = g_vftable_1aed70;
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
