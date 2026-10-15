class Base {
  public:
    Base();
    virtual void vf();
    char pad[0x14];
};
struct Tail {
    int l, m;
    Tail(int x) : l(x), m(x) {}
};
class MultiController : public Base {
  public:
    MultiController();
    virtual void vf();
    int a;
    float b, c;
    int d, e, f, x;
    float g;
    int h, i;
    char j;
    char pad2[3];
    int k;
    Tail tail;
};
MultiController::MultiController()
    : a(0), b(30.0f), c(1.0f), d(0), e(0), f(0), x(0), g(3.402823466e38f), h(0), i(0), j(1), k(0), tail(0) {}