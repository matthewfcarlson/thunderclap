extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20070[];
class Ref_20070 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_20070 {
  public:
    void* vptr;
    void Fin();
};
class Obj_20070 : public Base_20070 {
  public:
    char pad[24];
    Ref_20070* m;
    ~Obj_20070();
};
Obj_20070::~Obj_20070() {
    vptr = g_vftable_20070;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
