class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class MomentumXZAddTrack : public Base {
  public:
    MomentumXZAddTrack();
    virtual void f();
    int flag;
    int zero;
    float x, y;
};
MomentumXZAddTrack::MomentumXZAddTrack() : Base() {
    x = -1.0f;
    y = -1.0f;
    zero = 0;
    flag = 1;
}