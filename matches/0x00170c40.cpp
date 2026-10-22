class Track_170c40 {
  public:
    Track_170c40();
    virtual void f();
    int b;
    int a;
};
struct First {
    int x1, x2;
    float x3;
    First() : x1(0), x2(0), x3(-1.0f) {}
};
struct Second {
    int x4, x5, x6;
    float x7;
    Second() : x4(0), x5(0), x6(0), x7(2.0f) {}
};
class TeleportRelativeTrack : public Track_170c40 {
  public:
    TeleportRelativeTrack();
    virtual void f();
    int x0;
    First first;
    Second second;
};
TeleportRelativeTrack::TeleportRelativeTrack() : x0(0) {
    a = 1;
}