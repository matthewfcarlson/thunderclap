class Track_14dfe0 {
  public:
    Track_14dfe0();
    virtual void f();
    char pad[8];
    int a;
    float b;
    int c;
    int d;
    int e;
    int g;
};
class HitOrientToPushbackTrack : public Track_14dfe0 {
  public:
    HitOrientToPushbackTrack();
    virtual void f();
};
HitOrientToPushbackTrack::HitOrientToPushbackTrack() {
    a = 0;
    c = 0;
    e = 0;
    g = 0;
    b = -1.0f;
    d = -5;
}