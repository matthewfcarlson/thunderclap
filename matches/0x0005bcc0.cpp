class Track;
class Base {
  public:
    virtual void f();
    Base(int);
};
class ParamBranch_5bcc0 : public Base {
  public:
    ParamBranch_5bcc0(int, int);
    virtual void f();
    char pad[12];
    int value;
};
ParamBranch_5bcc0::ParamBranch_5bcc0(int a, int b) : Base(a), value(b) {}