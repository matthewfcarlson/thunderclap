extern "C" void _ReadWriteBarrier();
extern void* g_vftable_134e00[];
class Ref_134e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_134e00 {
  public:
    void* vptr;
    void Fin();
};
class HoverAction_134e00 : public Action_134e00 {
  public:
    char pad[28];
    Ref_134e00* m;
    ~HoverAction_134e00();
};
HoverAction_134e00::~HoverAction_134e00() {
    vptr = g_vftable_134e00;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
