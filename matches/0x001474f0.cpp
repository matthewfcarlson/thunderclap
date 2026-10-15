class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class GrappleStruggleTrack : public Base {
  public:
    GrappleStruggleTrack();
    virtual void f();
    int a;
    int b;
    float c;
    int d, e, g, h;
};
GrappleStruggleTrack::GrappleStruggleTrack() : Base() {
    b = 0;
    d = 0;
    e = 0;
    g = 0;
    h = 0;
    c = -1.0f;
    a = 1;
}