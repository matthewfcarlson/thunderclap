extern "C" void _ReadWriteBarrier();
extern void* g_vftable_18c70[];
class Ref_18c70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_18c70 {
  public:
    void* vptr;
    void Fin();
};
class Obj_18c70 : public Base_18c70 {
  public:
    char pad[24];
    Ref_18c70* m;
    ~Obj_18c70();
};
Obj_18c70::~Obj_18c70() {
    vptr = g_vftable_18c70;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
