class Track_239430 {
  public:
    virtual void Dummy();
    Track_239430();
    char pad[8];
};
class A {
  public:
    A();
    char bytes[12];
};
class B {
  public:
    B();
};
class ExecuteTrack_239430 : public Track_239430 {
  public:
    virtual void Dummy();
    ExecuteTrack_239430();
    int x;
    float y;
    A a;
    int z;
    B b;
};
ExecuteTrack_239430::ExecuteTrack_239430() : x(0), y(-1.0f), z(-1000) {}