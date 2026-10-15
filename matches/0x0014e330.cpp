class Base {
  public:
    Base();
    virtual void func();
};
class GroundSlideTrack : public Base {
  public:
    GroundSlideTrack();
    virtual void func();
    char pad4[8];
    int a;
    float b;
    int c;
    float d;
    float e;
    int f;
    float g;
    float h;
    int i;
    int j;
    int k;
};
GroundSlideTrack::GroundSlideTrack() : a(0), c(0), f(0), j(0), k(0) {
    b = -1.0f;
    d = 0.5f;
    e = 20.0f;
    g = 10.0f;
    h = 100.0f;
    i = -5;
}