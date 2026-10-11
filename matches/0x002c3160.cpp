extern "C" void _ReadWriteBarrier();
extern void* g_a[];
extern void* g_b[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    char pad[0x18];
    Ref* m1c;
    Ref* m20;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_a;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = g_b;
    if (flags & 1)
        operator delete(this);
    return this;
}
