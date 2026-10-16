class Base {
  public:
    Base(int);
    virtual void f();
};
class ParamName : public Base {
  public:
    ParamName(int, int);
    virtual void f();
    char pad[12];
    int value;
};
ParamName::ParamName(int a, int b) : Base(a), value(b) {}