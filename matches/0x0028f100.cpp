extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042cb44[];
class Ref_28f100 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_28f100 {
  public:
    void* vptr;
    void Fin();
};
class Obj_28f100 : public Base_28f100 {
  public:
    char pad[12];
    Ref_28f100* m;
    ~Obj_28f100();
};
Obj_28f100::~Obj_28f100() {
    vptr = g_vftable_0042cb44;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
