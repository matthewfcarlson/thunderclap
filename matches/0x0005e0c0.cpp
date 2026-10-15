class Base {
  public:
    Base();
    virtual void v0();
    char pad[4];
};
class A {
  public:
    A();
    char pad[8];
};
class B {
  public:
    B();
    char pad[12];
};
struct Fields {
    int x, y, z;
    float f;
    int one;
    Fields() : x(0), y(0), z(0), f(0.1f), one(1) {}
};
class COpportunityBallTrack : public Base {
  public:
    COpportunityBallTrack();
    virtual void v0();
    int m8;
    int mc;
    float m10;
    char pad14[4];
    A a;
    Fields fields;
    B b;
    B c;
};
COpportunityBallTrack::COpportunityBallTrack() : Base(), mc(0), m10(-1.0f), a(), fields(), b(), c() {
    m8 = 1;
}