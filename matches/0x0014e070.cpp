class Track_14e070 {
  public:
    Track_14e070();
    virtual void f();
    char pad[8];
};
class HitFloatTrack : public Track_14e070 {
  public:
    HitFloatTrack();
    int a;
    float d;
    char b;
    char gap2[3];
    int c;
    int e;
    int f;
    int g;
};
HitFloatTrack::HitFloatTrack() : Track_14e070() {
    a = 0;
    b = 0;
    c = 0;
    f = 0;
    g = 0;
    d = -1.0f;
    e = -5;
}