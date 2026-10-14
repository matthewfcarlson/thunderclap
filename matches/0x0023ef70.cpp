extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23ef70[];
class Ref_23ef70 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_23ef70 {
  public:
    void Fn();
};
class Helper_23ef70 {
  public:
    void Fn();
};
class A_23ef70 {
  public:
    void* vptr;
    char p[0x1c];
    Ref_23ef70* m20;
    Ref_23ef70* m24;
    Sub_23ef70 m28;
    A_23ef70* f2(unsigned char flags);
};
void operator delete(void*);
A_23ef70* A_23ef70::f2(unsigned char flags) {
    vptr = g_vftable_23ef70;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    m20->f1();
    m28.Fn();
    ((Helper_23ef70*)this)->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}
