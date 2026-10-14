extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22280[];
void operator delete(void*);
class Ref_22280 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22280 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22280 : public Base_22280 {
  public:
    char pad[24];
    Ref_22280* m;
    Obj_22280* f2(unsigned char flags);
};
Obj_22280* Obj_22280::f2(unsigned char flags) {
    vptr = g_vftable_22280;
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
