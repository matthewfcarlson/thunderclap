extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a6e50[];
class Ref_2a6e50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2a6e50 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2a6e50 : public Base_2a6e50 {
  public:
    char pad[60];
    Ref_2a6e50* m;
    ~Obj_2a6e50();
};
Obj_2a6e50::~Obj_2a6e50() {
    vptr = g_vftable_2a6e50;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
