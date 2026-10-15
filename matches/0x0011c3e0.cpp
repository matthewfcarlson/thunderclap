namespace hulkfight {
namespace ai {
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class PathFormationTrack : public Base {
  public:
    PathFormationTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f1;
    float g;
    int j, k, h, i;
};
PathFormationTrack::PathFormationTrack() : a(0), c(0), d(0), e(0), f1(0), h(0), i(0) {
    b = -1.0f;
    g = 1.0f;
    j = 3;
    k = 10;
}
} // namespace ai
} // namespace hulkfight
