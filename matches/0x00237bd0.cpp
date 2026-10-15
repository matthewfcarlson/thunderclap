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
class SequenceTrack : public Base {
  public:
    SequenceTrack();
    virtual void f();
    int flag;
    PartA a;
    int other;
    PartB b;
};
SequenceTrack::SequenceTrack() : Base(), a(), other(1), b() {
    flag = 1;
}