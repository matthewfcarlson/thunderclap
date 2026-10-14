class Ref_2828b0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Ref_2828b0* a;
    Ref_2828b0* b;
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