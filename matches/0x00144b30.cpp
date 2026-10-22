class Action_144b30 {
  public:
    virtual void F();
    char pad[0x18];
    Action_144b30();
};
class MotionBlurAction : public Action_144b30 {
  public:
    int value;
    MotionBlurAction(int);
};
MotionBlurAction::MotionBlurAction(int x) : Action_144b30(), value(0) {
    int* p = &value;
    *p = 0;
    value = x;
}