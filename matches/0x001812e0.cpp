class Base {
  public:
    Base();
    virtual void vf();
    char pad[4];
    int flag;
};
struct Tail {
    int h, i, j;
    Tail() : h(0), i(0), j(0) {}
};
class BallAndChainSpinTrack : public Base {
  public:
    BallAndChainSpinTrack();
    virtual void vf();
    int a;
    float b;
    int c;
    float d, e;
    int x;
    float angle;
    Tail tail;
};
BallAndChainSpinTrack::BallAndChainSpinTrack()
    : Base(), a(0), b(-1.0f), c(0), d(10.0f), e(3.0f), x(0), angle(6.2831855f) {
    flag = 1;
}