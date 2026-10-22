class Track_180e70 {
  public:
    Track_180e70();
    virtual void f();
    char pad[4];
};
class GrapplePropDamageTrack : public Track_180e70 {
  public:
    GrapplePropDamageTrack();
    int flag, a, b, c, d;
    virtual void f();
};
GrapplePropDamageTrack::GrapplePropDamageTrack() : Track_180e70(), a(0), b(0), c(0), d(0) {
    flag = 1;
}