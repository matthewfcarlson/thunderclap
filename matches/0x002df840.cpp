// Same code shape as 0x00284b50 (propagated; names are from that function)
class AnimationFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(int);
    char pad[0x18 - 4];
    int field;
};
void AnimationFrameController::vfunc_8(int x) {
    field = x;
}