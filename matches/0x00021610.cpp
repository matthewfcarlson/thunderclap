extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21610[];
class Ref_21610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21610 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21610 : public Base_21610 {
  public:
    char pad[24];
    Ref_21610* m;
    ~Obj_21610();
};
Obj_21610::~Obj_21610() {
    vptr = g_vftable_21610;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
