class ParamValueFloat_6c790 {
  public:
    virtual void Fn();
    ParamValueFloat_6c790(float);
    char pad[12];
};
class ParamFloatConstRange_06c790 : public ParamValueFloat_6c790 {
  public:
    virtual void Fn();
    float val;
    ParamFloatConstRange_06c790(float a, float b);
};
ParamFloatConstRange_06c790::ParamFloatConstRange_06c790(float a, float b) : ParamValueFloat_6c790(a) {
    val = b;
}