extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int);
};
class Base {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();

class Obj : public Base {
  public:
    char pad[0x18];
    void* m1c;
    Ref* m20;
    char p[4];
    Ref* m28;
    Ref* m2c;
    Obj* f2(unsigned char fl);
};
Obj* Obj::f2(unsigned char fl) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
