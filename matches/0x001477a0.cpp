class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class PartA {
  public:
    PartA();
    char pad[12];
};
class PartB {
  public:
    PartB();
};
class GrappleExecuteTrack : public Base {
  public:
    GrappleExecuteTrack();
    virtual void f();
    int a;
    float b;
    PartA p;
    int c;
    PartB q;
};
GrappleExecuteTrack::GrappleExecuteTrack() : Base(), a(0), b(-1.0f), p(), c(-1000), q() {}