extern "C" void _ReadWriteBarrier();
extern void* g_a_130080[];
class Ref_130080 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_130080 {
  public:
    void* vptr;
    void Fin();
};
class StatAction_130080 : public Action_130080 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_130080* m20;
    void f();
};
void StatAction_130080::f() {
    vptr = g_a_130080;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
