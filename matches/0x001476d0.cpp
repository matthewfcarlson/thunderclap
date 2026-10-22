class Track_1476d0 {
  public:
    virtual void f();
    Track_1476d0();
    char pad[4];
    int mode;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class GrappleHitReactionTrack : public Track_1476d0 {
  public:
    virtual void f();
    GrappleHitReactionTrack();
    int a, b, c, d;
    int gap;
    Sub sub;
    int e, f1, g;
    unsigned char flag;
    char pad2[3];
    int h, i, j, k, l, m, o;
};
GrappleHitReactionTrack::GrappleHitReactionTrack()
    : Track_1476d0(), a(0), b(0), c(0), d(0), sub(), e(0), f1(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), o(0) {
    flag = 1;
    mode = 3;
}