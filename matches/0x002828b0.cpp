class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Ref* a;
    Ref* b;
    void vfunc_13();
};
void CMotionTrail::vfunc_13() {
    if (a) {
        a->f1();
        a = 0;
    }
    if (b) {
        b->f1();
        b = 0;
    }
}