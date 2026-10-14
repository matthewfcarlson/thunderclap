extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20b90[];
class Ref_20b90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_20b90 {
  public:
    void* vptr;
    void Fin();
};
class Obj_20b90 : public Base_20b90 {
  public:
    char pad[24];
    Ref_20b90* m;
    ~Obj_20b90();
};
Obj_20b90::~Obj_20b90() {
    vptr = g_vftable_20b90;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
