class Track_170630 {
  public:
    Track_170630();
    virtual void f();
    char pad[4];
};
class MomentumXZAddTrack : public Track_170630 {
  public:
    MomentumXZAddTrack();
    virtual void f();
    int flag;
    int zero;
    float x, y;
};
MomentumXZAddTrack::MomentumXZAddTrack() : Track_170630() {
    x = -1.0f;
    y = -1.0f;
    zero = 0;
    flag = 1;
}