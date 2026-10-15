class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class BounceTrack : public Base {
  public:
    BounceTrack();
    virtual void f();
    int a;
    int c;
    float b;
    int d, z;
    float e, g, h;
    int i, j, k;
};
BounceTrack::BounceTrack() : c(0), d(0), z(0), j(0), k(0) {
    b = -1.0f;
    e = 7.0f;
    g = 10.0f;
    h = 1.57079637f;
    i = -5;
    a = 1;
}