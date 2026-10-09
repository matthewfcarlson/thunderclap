class BlendFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
    virtual void f7();
};
class PoseAnimationController : public BlendFrameController {
  public:
    char pad[12];
    unsigned char flag;
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void vfunc_6(int, char);
    void helper();
};
void PoseAnimationController::vfunc_6(int a, char b) {
    BlendFrameController::f6(a, 0);
    helper();
    if (flag == 1 || b == 1)
        BlendFrameController::f7();
}
