extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_ref[];
void operator delete(void*);
void operator delete[](void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Mem {
  public:
    ~Mem();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x14];
    void* vptr2;
    char pad1[4];
    Mem m20;
    char pad2[0x0b];
    Ref* m2c;
    char pad3[0x0c];
    void* m3c;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m3c)
        operator delete[](m3c);
    m20.~Mem();
    vptr2 = g_ref;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
