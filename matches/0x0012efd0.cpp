class Track_12efd0 {
  public:
    Track_12efd0();
    virtual void f();
    char pad[4];
};
class StatTrack : public Track_12efd0 {
  public:
    StatTrack();
    virtual void f();
    char pad2[4];
    int a;
    int b;
};
StatTrack::StatTrack() : Track_12efd0() {
    a = 0;
    b = 0;
}