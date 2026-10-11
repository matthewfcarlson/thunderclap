extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};

class Sub {
  public:
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x14];
    Sub s18;
    char pad2[7];
    Sub s20;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    s20.Fin();
    s18.Fin();
    Base::Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
