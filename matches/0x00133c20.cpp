namespace hulkfight {
namespace motion {
class Base {
  public:
    Base();
    virtual void f();
    int x;
    int flag;
};
class AirToGroundTargetTrack : public Base {
  public:
    AirToGroundTargetTrack();
    int a;
    float b, c, d, e, f, g;
    int h, i, j, k;
};
AirToGroundTargetTrack::AirToGroundTargetTrack()
    : a(0), b(-1.0f), c(0), d(50.0f), e(100.0f), f(100.0f), g(3.1415927f / 2.0f), h(0), i(-5), j(0), k(0) {
    flag = 1;
}
} // namespace motion
} // namespace hulkfight