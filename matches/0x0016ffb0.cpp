extern "C" void _ReadWriteBarrier();
class Track_16ffb0 {
  public:
    Track_16ffb0();
    virtual void f();
    char pad[4];
    int count;
};
class Sub_16ffb0 {
  public:
    Sub_16ffb0();
    char pad[8];
};
class JointRelativeTrack : public Track_16ffb0 {
  public:
    JointRelativeTrack();
    virtual void f();
    int a;
    float b;
    char gap[4];
    Sub_16ffb0 sub;
    char flag0;
    char flag1;
    char gap2[2];
    int x24, x28, x2c;
    char flag30;
    char gap3[3];
    int x34, x38, x3c, x40;
    float x44, x48;
};
JointRelativeTrack::JointRelativeTrack()
    : Track_16ffb0(), a(0), b(-1.0f), sub(), flag0(0), flag1(0), x24(0), x28(0), x2c(0), flag30(0), x34(0), x38(0),
      x3c(0) {
    _ReadWriteBarrier();
    x44 = 0.1f;
    x48 = 0.1f;
    x40 = -5;
    count = 1;
}