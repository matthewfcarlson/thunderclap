extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1614a0[];
extern void* g_vftable2[];
class Ref_1614a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1614a0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
class Obj_1614a0 : public Base_1614a0 {
  public:
    char p[0x18];
    Ref_1614a0* m1c;
    Ref_1614a0* m20;
    char p2[0x20];
    void* m44;
    Obj_1614a0* f2(unsigned char fl);
};
Obj_1614a0* Obj_1614a0::f2(unsigned char fl) {
    vptr = g_vftable_1614a0;
    _ReadWriteBarrier();
    if (m44)
        m44 = 0;
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
