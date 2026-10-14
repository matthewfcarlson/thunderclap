extern "C" void _ReadWriteBarrier();
extern void* g_vftable_201f0[];
class Ref_201f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_201f0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_201f0 : public Base_201f0 {
  public:
    char pad[24];
    Ref_201f0* m;
    ~Obj_201f0();
};
Obj_201f0::~Obj_201f0() {
    vptr = g_vftable_201f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
