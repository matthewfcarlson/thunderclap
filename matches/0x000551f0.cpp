class Base {
  public:
    Base(int arg);
    virtual void f();
};

class ParamNameConstList : public Base {
  public:
    ParamNameConstList(int a, int b);
    virtual void f();
    char pad[12];
    int m10;
};

ParamNameConstList::ParamNameConstList(int a, int b) : Base(a) {
    m10 = b;
}
