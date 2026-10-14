extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21520[];
class Ref_21520 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21520 {
  public:
    void* vptr;
    void Fin();
};
class Obj_21520 : public Base_21520 {
  public:
    char pad[24];
    Ref_21520* m;
    ~Obj_21520();
};
Obj_21520::~Obj_21520() {
    vptr = g_vftable_21520;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
