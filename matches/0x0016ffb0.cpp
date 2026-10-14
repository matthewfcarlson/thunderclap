extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
    int count;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class JointRelativeTrack : public Base {
  public:
    JointRelativeTrack();
    virtual void f();
    int a;
    float b;
    char gap[4];
    Sub sub;
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
    : Base(), a(0), b(-1.0f), sub(), flag0(0), flag1(0), x24(0), x28(0), x2c(0), flag30(0), x34(0), x38(0),
      x3c(0) {
    _ReadWriteBarrier();
    x44 = 0.1f;
    x48 = 0.1f;
    x40 = -5;
    count = 1;
}