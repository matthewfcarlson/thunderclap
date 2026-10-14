extern "C" void _ReadWriteBarrier();
extern void* g_vftable_134e00[];
class Ref_134e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_134e00 {
  public:
    void* vptr;
    void Fin();
};
class Obj_134e00 : public Base_134e00 {
  public:
    char pad[28];
    Ref_134e00* m;
    ~Obj_134e00();
};
Obj_134e00::~Obj_134e00() {
    vptr = g_vftable_134e00;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
