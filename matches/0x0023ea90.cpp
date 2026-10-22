class Track_23ea90 {
  public:
    Track_23ea90();
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
class SpawnTrack : public Track_23ea90 {
  public:
    SpawnTrack();
    virtual void f();
    int flag;
    int n;
    float value;
    PartA a;
    PartB b;
};
SpawnTrack::SpawnTrack() : Track_23ea90(), n(0), value(-1.0f), a(), b() {
    flag = 1;
}