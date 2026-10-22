class Track_170f00 {
  public:
    Track_170f00();
    virtual void f();
    char pad[4];
};
class VisibilityTrack : public Track_170f00 {
  public:
    VisibilityTrack();
    virtual void f();
    int value;
    int other;
    char flag;
};
VisibilityTrack::VisibilityTrack() : Track_170f00() {
    flag = 1;
    value = 1;
    other = 0;
}