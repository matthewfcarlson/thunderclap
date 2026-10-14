extern "C" void _ReadWriteBarrier();
extern void* g_vftable_117100[];
class Ref_117100 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_117100 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_117100 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_117100* m20;
    Ref_117100* m24;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_117100;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
