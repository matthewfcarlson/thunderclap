extern "C" void _ReadWriteBarrier();
extern int TeleportVtable;
class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper {
  public:
    void Clean();
};
class Base {
  public:
    int* vptr;
    char pad[0x18];
    void BaseClean();
};
class TeleportRelativeAction : public Base {
  public:
    int m1c;
    Ref* m20;
    int pad24;
    Helper helper;
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
