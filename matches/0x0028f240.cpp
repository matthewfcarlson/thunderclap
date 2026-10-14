extern "C" void _ReadWriteBarrier();
extern void* g_vftable_28f240[];
void operator delete(void*);
class Ref_28f240 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_28f240 {
  public:
    void* vptr;
    void Fin();
};
class Obj_28f240 : public Base_28f240 {
  public:
    char pad[12];
    Ref_28f240* m;
    Obj_28f240* f2(unsigned char flags);
};
Obj_28f240* Obj_28f240::f2(unsigned char flags) {
    vptr = g_vftable_28f240;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
