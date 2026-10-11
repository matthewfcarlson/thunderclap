extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_base_vftable[];
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
    char pad[4];
    Ref* m8;
    char pad2[0x1c];
    void* m28;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m8) {
        m8->Release();
        m8 = 0;
    }
    operator delete[](m28);
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
