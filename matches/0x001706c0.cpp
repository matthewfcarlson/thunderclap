class Base {
  public:
    Base();
    virtual void v();
};
class TargetBreakTrack : public Base {
  public:
    TargetBreakTrack();
    virtual void v();
    char pad[4];
    int a;
    int b;
};
TargetBreakTrack::TargetBreakTrack() : Base() {
    b = 0;
    a = 1;
}