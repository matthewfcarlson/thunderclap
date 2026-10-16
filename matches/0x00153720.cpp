class Base {
  public:
    Base(int);
    virtual void f();
};
class Range : public Base {
  public:
    Range(int, int);
    char pad[12];
    int value;
    virtual void f();
};
Range::Range(int a, int b) : Base(a) {
    value = b;
}