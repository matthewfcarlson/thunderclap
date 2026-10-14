extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21400[];
class Ref_21400 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21400 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21400 : public Base_21400 {
  public:
    char pad[24];
    Ref_21400* m;
    ~Obj_21400();
};
Obj_21400::~Obj_21400() {
    vptr = g_vftable_21400;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
