extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
void operator delete(void*);
void operator delete[](void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
};
class Obj : public Base {
  public:
    char pad[8];
    Ref* mc;
    void* m10;
    void* m14;
    Obj* f0(unsigned char flags);
};
Obj* Obj::f0(unsigned char flags) {
    vptr = g_vftable;
    if (!mc) {
        operator delete[](m14);
    } else {
        _ReadWriteBarrier();
        if (mc) {
            mc->Release();
            mc = 0;
        }
    }
    m14 = 0;
    vptr = g_vftable2;
    if (flags & 1)
        operator delete(this);
    return this;
}
