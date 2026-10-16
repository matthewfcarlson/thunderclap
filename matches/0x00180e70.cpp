class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class GrapplePropDamageTrack : public Base {
  public:
    GrapplePropDamageTrack();
    int flag, a, b, c, d;
    virtual void f();
};
GrapplePropDamageTrack::GrapplePropDamageTrack() : Base(), a(0), b(0), c(0), d(0) {
    flag = 1;
}