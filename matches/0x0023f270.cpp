extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23f270[];
class Ref_23f270 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_23f270 {
  public:
    void* vptr;
    void Fin();
};
class Obj_23f270 : public Base_23f270 {
  public:
    char pad[28];
    Ref_23f270* m;
    ~Obj_23f270();
};
Obj_23f270::~Obj_23f270() {
    vptr = g_vftable_23f270;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
