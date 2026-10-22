class Track_14e190 {
  public:
    Track_14e190();
    virtual void f();
    char pad[4];
};
class HitPushbackAddTrack : public Track_14e190 {
  public:
    HitPushbackAddTrack();
    int a;
    int b;
    float c;
};
HitPushbackAddTrack::HitPushbackAddTrack() : Track_14e190() {
    b = 0;
    c = 1.0f;
    a = 1;
}