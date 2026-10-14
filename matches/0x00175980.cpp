extern "C" void _ReadWriteBarrier();
extern int TeleportVtable;
class Ref_175980 {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_175980 {
  public:
    void Clean();
};
class Base_175980 {
  public:
    int* vptr;
    char pad[0x18];
    void BaseClean();
};
class TeleportRelativeAction : public Base_175980 {
  public:
    int m1c;
    Ref_175980* m20;
    int pad24;
    Helper_175980 helper;
    void Destroy();
};
void TeleportRelativeAction::Destroy() {
    vptr = &TeleportVtable;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    helper.Clean();
    BaseClean();
}
