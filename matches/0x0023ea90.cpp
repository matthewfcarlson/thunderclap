class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
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
class SpawnTrack : public Base {
  public:
    SpawnTrack();
    virtual void f();
    int flag;
    int n;
    float value;
    PartA a;
    PartB b;
};
SpawnTrack::SpawnTrack() : Base(), n(0), value(-1.0f), a(), b() {
    flag = 1;
}