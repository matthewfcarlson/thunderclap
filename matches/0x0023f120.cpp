class Track_23f120 {
  public:
    Track_23f120();
    virtual void f();
};
class Part {
  public:
    Part();
};
class BreakPointTrack : public Track_23f120 {
  public:
    BreakPointTrack();
    virtual void f();
    int unused;
    int flag;
    int zero;
    Part part;
};
BreakPointTrack::BreakPointTrack() : Track_23f120(), zero(0), part() {
    flag = 1;
}