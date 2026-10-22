class ParamValueFloat_153720 {
  public:
    ParamValueFloat_153720(int);
    virtual void f();
};
class ParamFloatConstRange_153720 : public ParamValueFloat_153720 {
  public:
    ParamFloatConstRange_153720(int, int);
    char pad[12];
    int value;
    virtual void f();
};
ParamFloatConstRange_153720::ParamFloatConstRange_153720(int a, int b) : ParamValueFloat_153720(a) {
    value = b;
}