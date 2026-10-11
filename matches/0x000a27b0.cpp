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
    char pad[0x34c];
    Ref* m350;
    void Cam29();
    void Fin();
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m350) {
        m350->Release();
        m350 = 0;
    }
    Cam29();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
