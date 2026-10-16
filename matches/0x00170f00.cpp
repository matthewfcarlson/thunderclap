class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class VisibilityTrack : public Base {
  public:
    VisibilityTrack();
    virtual void f();
    int value;
    int other;
    char flag;
};
VisibilityTrack::VisibilityTrack() : Base() {
    flag = 1;
    value = 1;
    other = 0;
}