extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20170[];
class Ref_20170 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_20170 {
  public:
    void* vptr;
    void Fin();
};
class Obj_20170 : public Base_20170 {
  public:
    char pad[24];
    Ref_20170* m;
    ~Obj_20170();
};
Obj_20170::~Obj_20170() {
    vptr = g_vftable_20170;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
