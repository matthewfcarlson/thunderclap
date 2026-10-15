class Base {
  public:
    virtual void Dummy();
    Base();
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
class fight_ExecuteTrack : public Base {
  public:
    virtual void Dummy();
    fight_ExecuteTrack();
    int x;
    float y;
    A a;
    int z;
    B b;
};
fight_ExecuteTrack::fight_ExecuteTrack() : x(0), y(-1.0f), z(-1000) {}