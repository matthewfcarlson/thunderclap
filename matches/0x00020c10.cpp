extern "C" void _ReadWriteBarrier();
extern void* g_vftable_20c10[];
class Ref_20c10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_20c10 {
  public:
    void* vptr;
    void Fin();
};
class Obj_20c10 : public Base_20c10 {
  public:
    char pad[24];
    Ref_20c10* m;
    ~Obj_20c10();
};
Obj_20c10::~Obj_20c10() {
    vptr = g_vftable_20c10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
