extern "C" void _ReadWriteBarrier();
extern void* g_vftable_200f0[];
class Ref_200f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_200f0 {
  public:
    void* vptr;
    void Fin();
};
class CAction_200f0 : public Action_200f0 {
  public:
    char pad[24];
    Ref_200f0* m;
    ~CAction_200f0();
};
CAction_200f0::~CAction_200f0() {
    vptr = g_vftable_200f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
