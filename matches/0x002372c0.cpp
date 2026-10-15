namespace fight {
class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
    int flag;
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
class OpportunityTrack : public Base {
  public:
    OpportunityTrack();
    virtual void f();
    int a;
    float b;
    int c;
    PartA d;
    int e;
    PartB g;
};
OpportunityTrack::OpportunityTrack() : Base(), a(0), b(-1.0f), c(0), d(), e(0), g() {
    flag = 1;
}
} // namespace fight