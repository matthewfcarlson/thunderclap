class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
    int n;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class CJointTrack : public Base {
  public:
    CJointTrack();
    int a;
    float b;
    char pad2[4];
    Sub sub;
    char flag;
    char pad3[3];
    int c, d, e;
    char flag2;
    char pad4[3];
    int f, g, h, i, j, k;
};
CJointTrack::CJointTrack()
    : a(0), b(-1.0f), flag(0), c(0), d(0), e(0), flag2(0), f(0), g(0), h(0), j(0), k(0) {
    i = -1;
    n = 1;
}