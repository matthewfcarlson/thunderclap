// Same code shape as 0x00144b30 (propagated; names are from that function)
class MotionBase_144aa0 {
  public:
    virtual void F();
    char pad[0x18];
    MotionBase_144aa0();
};
class SlowMotionAction_144aa0 : public MotionBase_144aa0 {
  public:
    int value;
    SlowMotionAction_144aa0(int);
};
SlowMotionAction_144aa0::SlowMotionAction_144aa0(int x) : MotionBase_144aa0(), value(0) {
    int* p = &value;
    *p = 0;
    value = x;
}