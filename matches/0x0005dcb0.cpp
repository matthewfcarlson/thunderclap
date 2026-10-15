class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class CProceduralDurationAnimationTrack : public Base {
  public:
    CProceduralDurationAnimationTrack();
    char p0[4];
    int a;
    float b;
    int c;
    Sub s1;
    float d;
    int e, f;
    float g;
    int h;
    char p1[4];
    Sub s2;
    int i, j, k;
    char l;
};
CProceduralDurationAnimationTrack::CProceduralDurationAnimationTrack()
    : Base(), a(0), b(1.0f), c(0), s1(), d(1.0f), e(0), f(0), g(-1.0f), h(0), s2(), i(0), j(0), k(0), l(0) {}