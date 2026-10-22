class ParamValueInt_153de0 {
  public:
    virtual void f();
    ParamValueInt_153de0(int);
};
class ParamIntConstRange_153de0 : public ParamValueInt_153de0 {
  public:
    virtual void f();
    char pad[12];
    int value;
    ParamIntConstRange_153de0(int a, int b);
};
ParamIntConstRange_153de0::ParamIntConstRange_153de0(int a, int b) : ParamValueInt_153de0(a), value(b) {}