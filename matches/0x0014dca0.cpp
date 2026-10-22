class Track_14dca0 {
  public:
    Track_14dca0();
    virtual void f();
    char pad[8];
};
class Part_14dca0 {
  public:
    Part_14dca0();
    char pad[8];
};
class HitReactionFloatTrack : public Track_14dca0 {
  public:
    HitReactionFloatTrack();
    virtual void f();
    int a, b, c;
    Part_14dca0 part;
    int x20, x24;
    float x28, x2c;
    int x30, x34, x38, x3c, x40, x44, x48, x4c;
    char x50;
};
HitReactionFloatTrack::HitReactionFloatTrack()
    : a(0), b(0), c(0), part(), x20(0), x24(0), x28(-1.0f), x2c(-1.0f), x30(0), x34(0), x38(0), x3c(0),
      x40(0), x44(0), x48(0), x4c(0), x50(0) {
    *(int*)((char*)this + 8) = 3;
}