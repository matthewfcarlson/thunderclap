class Track;
class Base {
  public:
    virtual void f();
    Base(int);
};
class Branch : public Base {
  public:
    Branch(int, int);
    virtual void f();
    char pad[12];
    int value;
};
Branch::Branch(int a, int b) : Base(a), value(b) {}