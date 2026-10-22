class Track_18cea0 {
  public:
    Track_18cea0();
    virtual void f();
    char pad[4];
    int n;
};
class Part {
  public:
    Part();
    char pad[8];
};
class VarAssignTrack : public Track_18cea0 {
  public:
    VarAssignTrack();
    virtual void f();
    int a;
    Part part;
    int b, c, d;
    char flag;
};
VarAssignTrack::VarAssignTrack() : Track_18cea0(), a(0), part(), b(0), c(0), d(0), flag(0) {
    n = 1;
}