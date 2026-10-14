extern void* g_vftable_11cdd0[];
extern "C" void _ReadWriteBarrier();
class Ref_11cdd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_11cdd0 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_11cdd0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_11cdd0* m20;
    Ref_11cdd0* m24;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_11cdd0;
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
