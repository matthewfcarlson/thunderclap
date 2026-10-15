namespace hulkfight {
namespace motion {
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Part {
  public:
    Part();
    char pad[8];
};
class CivilianAnimationTrack : public Base {
  public:
    CivilianAnimationTrack();
    virtual void f();
    int a;
    float b;
    char pad2[4];
    Part part;
    float c;
    int d;
    char e;
    char pad3[3];
    float g;
};
CivilianAnimationTrack::CivilianAnimationTrack()
    : Base(), a(0), b(-1.0f), part(), c(1.0f), d(0), e(0), g(0.1f) {
    *(int*)((char*)this + 8) = 1;
}
} // namespace motion
} // namespace hulkfight