class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Middle : public Base {
  public:
    Middle() {
        a = 0;
        b = 0;
        c = 0;
    }
    int a;
    float x;
    float y;
    int z;
    int b;
    int c;
};
class FlyingDashTrack : public Middle {
  public:
    FlyingDashTrack();
    virtual void f();
};
FlyingDashTrack::FlyingDashTrack() {
    x = -1.0f;
    y = 50.0f;
    z = -5;
}