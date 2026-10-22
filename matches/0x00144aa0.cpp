// Same code shape as 0x00144b30 (propagated; names are from that function)
class Action_144aa0 {
  public:
    virtual void F();
    char pad[0x18];
    Action_144aa0();
};
class SlowMotionAction_144aa0 : public Action_144aa0 {
  public:
    int value;
    SlowMotionAction_144aa0(int);
};
SlowMotionAction_144aa0::SlowMotionAction_144aa0(int x) : Action_144aa0(), value(0) {
    int* p = &value;
    *p = 0;
    value = x;
}