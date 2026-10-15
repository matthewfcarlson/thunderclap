class Base {
  public:
    Base();
    virtual void f();
    int x;
    int flag;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class PropSpawnTrack : public Base {
  public:
    PropSpawnTrack();
    virtual void f();
    int a, b;
    char gap[4];
    Sub s;
    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
};
PropSpawnTrack::PropSpawnTrack()
    : a(0), b(0), d0(0), d1(0), d2(0), d3(0), d4(0), d5(0), d6(0), d7(0), d8(0), d9(0), d10(0), d11(0) {
    flag = 1;
}