class Track;
class ParamValueBranch_5bcc0 {
  public:
    virtual void f();
    ParamValueBranch_5bcc0(int);
};
class ParamBranch_5bcc0 : public ParamValueBranch_5bcc0 {
  public:
    ParamBranch_5bcc0(int, int);
    virtual void f();
    char pad[12];
    int value;
};
ParamBranch_5bcc0::ParamBranch_5bcc0(int a, int b) : ParamValueBranch_5bcc0(a), value(b) {}