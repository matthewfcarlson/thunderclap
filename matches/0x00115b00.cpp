class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class Sub {
  public:
    void Init();
};
class MotionLocatorTrack : public Base {
  public:
    MotionLocatorTrack();
    virtual void f();
    char pad2[4];
    int a;
    float b, c;
    int d, e, f1, g;
    char h, i, j, k;
    char pad3[4];
    Sub sub;
};
MotionLocatorTrack::MotionLocatorTrack() : Base() {
    a = 0;
    b = -1.0f;
    c = 1.0f;
    d = 0;
    e = 0;
    f1 = 0;
    g = 0;
    h = 1;
    i = 0;
    j = 0;
    k = 0;
    sub.Init();
}