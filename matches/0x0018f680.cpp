extern "C" void _ReadWriteBarrier();
extern void* g_vftable_18f680[];
class Ref_18f680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_18f680 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_18f680 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_18f680* m20;
    Ref_18f680* m24;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_18f680;
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
