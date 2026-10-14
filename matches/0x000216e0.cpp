extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_216e0[];
void operator delete(void*);
class Ref_216e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_216e0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_216e0 : public Base_216e0 {
  public:
    char pad_1c[0x18];
    Ref_216e0* m1c;
    char pad_24[0x4];
    Ref_216e0* m24;
    Obj_216e0* f2(unsigned char flags);
};
Obj_216e0* Obj_216e0::f2(unsigned char flags) {
    vptr = gD;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = gA_216e0;
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
