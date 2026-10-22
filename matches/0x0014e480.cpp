class Track_14e480 {
  public:
    Track_14e480();
    virtual void f();
};
class NoHitPushbackTrack : public Track_14e480 {
  public:
    NoHitPushbackTrack();
    char pad[4];
    int a;
    int b;
    float c;
    virtual void f();
};
NoHitPushbackTrack::NoHitPushbackTrack() {
    b = 0;
    c = -1.0f;
    a = 1;
}