extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_183c60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_183c60 {
  public:
    void* vptr;
    void Fin();
};
class Obj_183c60 : public Base_183c60 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_183c60* m20;
    ~Obj_183c60() throw();
};
Obj_183c60::~Obj_183c60() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
