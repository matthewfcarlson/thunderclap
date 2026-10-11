extern "C" void _ReadWriteBarrier();
class Obj {
  public:
    virtual void F0();
    virtual void F1();
};
class Base {
  public:
    void Finish();
};
class TargetIconDistanceAction : public Base {
  public:
    int vptr;
    char pad04[0x18];
    Obj* m1c;
    Obj* m20;
    void Clean();
};
extern int vt;
void TargetIconDistanceAction::Clean() {
    vptr = (int)&vt;
    _ReadWriteBarrier();
    Obj* p = m20;
    if (p) {
        p->F1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Finish();
}