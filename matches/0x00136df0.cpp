class ParamValueInt_136df0 {
  public:
    ParamValueInt_136df0(int);
    virtual void f();
};
class ParamIntConstRange_136df0 : public ParamValueInt_136df0 {
  public:
    ParamIntConstRange_136df0(int, int);
    virtual void f();
    char pad[12];
    int v;
};
ParamIntConstRange_136df0::ParamIntConstRange_136df0(int a, int b) : ParamValueInt_136df0(a), v(b) {}