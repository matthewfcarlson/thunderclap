extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1d370[];
class Ref_1d370 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1d370 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1d370 : public Base_1d370 {
  public:
    char pad[24];
    Ref_1d370* m;
    ~Obj_1d370();
};
Obj_1d370::~Obj_1d370() {
    vptr = g_vftable_1d370;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
