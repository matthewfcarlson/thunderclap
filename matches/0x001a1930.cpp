class Base {
  public:
    Base(int);
    virtual void f();
    char pad[12];
};
class ParamScript_1a1930 : public Base {
  public:
    ParamScript_1a1930(int, int);
    virtual void f();
    int value;
};
ParamScript_1a1930::ParamScript_1a1930(int a, int b) : Base(a) {
    value = b;
}