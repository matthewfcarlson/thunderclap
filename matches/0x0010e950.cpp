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
    void Fin();
};

class Obj : public Base {
  public:
    char pad[0xc];
    void* m;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    operator delete[](m);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
