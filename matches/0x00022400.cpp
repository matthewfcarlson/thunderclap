extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_22400[];
void operator delete(void*);
class Ref_22400 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22400 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22400 : public Base_22400 {
  public:
    char pad_1c[0x18];
    Ref_22400* m1c;
    char pad_28[0x8];
    Ref_22400* m28;
    Obj_22400* f2(unsigned char flags);
};
Obj_22400* Obj_22400::f2(unsigned char flags) {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    vptr = gA_22400;
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
