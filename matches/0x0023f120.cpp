class Base {
  public:
    Base();
    virtual void f();
};
class Part {
  public:
    Part();
};
class BreakPointTrack : public Base {
  public:
    BreakPointTrack();
    virtual void f();
    int unused;
    int flag;
    int zero;
    Part part;
};
BreakPointTrack::BreakPointTrack() : Base(), zero(0), part() {
    flag = 1;
}