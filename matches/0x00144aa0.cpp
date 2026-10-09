// Same code shape as 0x00144b30 (propagated; names are from that function)
class MotionBase {
  public:
    virtual void F();
    char pad[0x18];
    MotionBase();
};
class MotionBlurAction : public MotionBase {
  public:
    int value;
    MotionBlurAction(int);
};
MotionBlurAction::MotionBlurAction(int x) : MotionBase(), value(0) {
    int* p = &value;
    *p = 0;
    value = x;
}