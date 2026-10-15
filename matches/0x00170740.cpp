extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class Part {
  public:
    Part();
    char pad[8];
};
class PushOutTrack : public Base {
  public:
    PushOutTrack();
    char pad0[4];
    int a;
    float b;
    char pad1[4];
    Part part;
    int c, d, e, f, g;
    float h, i, j;
    char flag;
};
PushOutTrack::PushOutTrack() : Base(), a(0), b(-1.0f), part(), c(0), d(0), e(0), f(0), g(0) {
    h = -1.0f;
    _ReadWriteBarrier();
    flag = 0;
    i = 1.0f;
    j = 10.0f;
    *(int*)((char*)this + 8) = 1;
}