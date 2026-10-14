extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1d260[];
class Ref_1d260 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1d260 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1d260 : public Base_1d260 {
  public:
    char pad[24];
    Ref_1d260* m;
    ~Obj_1d260();
};
Obj_1d260::~Obj_1d260() {
    vptr = g_vftable_1d260;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
