extern "C" void _ReadWriteBarrier();
extern void* g_vftable_183af0[];
extern void* g_vftable2[];
class Ref_183af0 {
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
class Base_183af0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();

class Obj_183af0 : public Base_183af0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_183af0* m20;
    Ref_183af0* m24;
    Ref_183af0* m28;
    ~Obj_183af0() throw();
};
Obj_183af0::~Obj_183af0() throw() {
    vptr = g_vftable_183af0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    Fin();
}
