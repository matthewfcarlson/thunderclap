extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
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
void Free(void*) throw();

class Obj : public Base {
  public:
    char pad[8];
    Ref* mc;
    Obj* f0(unsigned char fl);
};
Obj* Obj::f0(unsigned char fl) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    Ref* t = mc;
    if (t) {
        mc = 0;
        t->Release();
    }
    if (fl & 1)
        Free(this);
    return this;
}
