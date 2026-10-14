class Base {
  public:
    Base();
    virtual void v();
    char pad[4];
    int flag;
};
class Elem {
  public:
    Elem();
    char bytes[8];
};
class AnimationPhaseMatchedTrack : public Base {
  public:
    AnimationPhaseMatchedTrack();
    virtual void v();
    int c;
    float ten;
    char pad14[4];
    Elem e;
    int a, b;
    float neg;
    char pad2c[4];
    Elem e2;
    int color;
    float x, y;
};
AnimationPhaseMatchedTrack::AnimationPhaseMatchedTrack()
    : Base(), c(0), ten(-1.0f), e(), a(0), b(0), neg(-1.0f), e2(), color(-1), x(0.1f), y(0.1f) {
    flag = 1;
}