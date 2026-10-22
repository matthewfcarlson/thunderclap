class Track_1706c0 {
  public:
    Track_1706c0();
    virtual void v();
};
class TargetBreakTrack : public Track_1706c0 {
  public:
    TargetBreakTrack();
    virtual void v();
    char pad[4];
    int a;
    int b;
};
TargetBreakTrack::TargetBreakTrack() : Track_1706c0() {
    b = 0;
    a = 1;
}