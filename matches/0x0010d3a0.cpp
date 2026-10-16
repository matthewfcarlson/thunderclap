class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class ButtonTrack : public Base {
  public:
    ButtonTrack();
    virtual void f();
    int a;
    float v;
    int b;
    int c;
    int d;
    int e;
};
ButtonTrack::ButtonTrack() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    v = -1.0f;
}