extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f690[];
class Ref_1f690 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f690 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1f690 : public Base_1f690 {
  public:
    char pad[24];
    Ref_1f690* m;
    ~Obj_1f690();
};
Obj_1f690::~Obj_1f690() {
    vptr = g_vftable_1f690;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
