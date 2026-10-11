extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    void* m4;
    char pad[0xc];
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
    if (m4)
        m4 = 0;
    if (flags & 1)
        operator delete(this);
    return this;
}
