extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class CTrack_5df10 : public Base {
  public:
    int a, b, c;
    CTrack_5df10() : Base(), a(0), b(0), c(0) {}
};
class CSnapToWallTrack : public CTrack_5df10 {
  public:
    CSnapToWallTrack();
    int d, e, f2;
    char flag;
    char pad2[3];
    int g, h, i;
    virtual void f();
};
CSnapToWallTrack::CSnapToWallTrack() : CTrack_5df10() {
    _ReadWriteBarrier();
    d = 0;
    e = 0;
    f2 = 0;
    flag = 0;
    h = 0;
    i = 0;
    g = -10;
}