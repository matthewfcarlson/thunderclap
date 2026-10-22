class ParamValueFloat_6c740 {
  public:
    virtual void f();
    ParamValueFloat_6c740(int);
    char pad[12];
};
class ParamFloatConstRange_06c740 : public ParamValueFloat_6c740 {
  public:
    virtual void f();
    int value;
    ParamFloatConstRange_06c740(int a, int b);
};
ParamFloatConstRange_06c740::ParamFloatConstRange_06c740(int a, int b) : ParamValueFloat_6c740(a), value(b) {}