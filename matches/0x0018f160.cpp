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
    int a, b;
};
class ImpulseVelocityTrack : public Base {
  public:
    ImpulseVelocityTrack();
    virtual void f();
    int x;
    Sub sub;
    int vals[9];
    char flag;
    char pad2[3];
    float scale;
};
ImpulseVelocityTrack::ImpulseVelocityTrack() : Base(), x(0), sub() {
    for (int i = 0; i < 9; i++)
        vals[i] = 0;
    flag = 0;
    scale = 1.0f;
    n = 1;
}