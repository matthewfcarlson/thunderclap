class ParamValueFloat_6c510 {
  public:
    ParamValueFloat_6c510(int);
    virtual void f();
};
class ParamFloatConstRange : public ParamValueFloat_6c510 {
  public:
    ParamFloatConstRange(int, int);
    char pad[12];
    int value;
    virtual void f();
};
ParamFloatConstRange::ParamFloatConstRange(int a, int b) : ParamValueFloat_6c510(a) {
    value = b;
}