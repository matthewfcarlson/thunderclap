class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
    int n;
};
class Part {
  public:
    Part();
    char pad[8];
};
class VarAssignTrack : public Base {
  public:
    VarAssignTrack();
    virtual void f();
    int a;
    Part part;
    int b, c, d;
    char flag;
};
VarAssignTrack::VarAssignTrack() : Base(), a(0), part(), b(0), c(0), d(0), flag(0) {
    n = 1;
}