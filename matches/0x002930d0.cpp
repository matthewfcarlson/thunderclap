extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042cf7c[];
class Ref_2930d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2930d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2930d0 : public Base_2930d0 {
  public:
    char pad[272];
    Ref_2930d0* m;
    ~Obj_2930d0();
};
Obj_2930d0::~Obj_2930d0() {
    vptr = g_vftable_0042cf7c;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
