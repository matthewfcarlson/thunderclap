extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
extern void* g_vB[];
void operator delete(void*);
class Ref_21cc0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21cc0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21cc0 : public Base_21cc0 {
  public:
    char pad[0x1c - 4];
    Ref_21cc0* m1c;
    char pad2[4];
    Ref_21cc0* m24;
    Obj_21cc0* f2(unsigned char flags);
};
Obj_21cc0* Obj_21cc0::f2(unsigned char flags) {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = g_vB;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
