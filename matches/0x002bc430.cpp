extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_base_vftable[];
void operator delete(void*);
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
    char pad[0x10];
    Ref* m14;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
