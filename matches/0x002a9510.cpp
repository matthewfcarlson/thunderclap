extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a9510[];
class Ref_2a9510 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2a9510 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2a9510 : public Base_2a9510 {
  public:
    char pad[60];
    Ref_2a9510* m;
    ~Obj_2a9510();
};
Obj_2a9510::~Obj_2a9510() {
    vptr = g_vftable_2a9510;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
