extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2bb5c0[];
extern void* g_vftable2[];
class Ref_2bb5c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2bb5c0 {
  public:
    void* vptr;
};
class Obj_2bb5c0 : public Base_2bb5c0 {
  public:
    char pad[0x10];
    Ref_2bb5c0* m;
    ~Obj_2bb5c0();
};
Obj_2bb5c0::~Obj_2bb5c0() {
    vptr = g_vftable_2bb5c0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    vptr = g_vftable2;
}
