class Action {
    char pad[0x20];

  public:
    int value;
};
class SlowMotionAction : public Action {
  public:
    void vfunc_4();
};
struct Receiver_1442f0 {
    void call(int);
};
struct GlobalObj_1442f0 {
    char pad[0x58];
    Receiver_1442f0* member;
};
extern GlobalObj_1442f0* gObj_1442f0;
void SlowMotionAction::vfunc_4() {
    gObj_1442f0->member->call(value);
}