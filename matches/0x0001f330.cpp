extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f330[];
class Ref_1f330 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f330 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1f330 : public Base_1f330 {
  public:
    char pad[24];
    Ref_1f330* m;
    ~Obj_1f330();
};
Obj_1f330::~Obj_1f330() {
    vptr = g_vftable_1f330;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
