class ParamBase {
  public:
    ParamBase(int);
    virtual void f();
};
class ParamFloatConstRange : public ParamBase {
  public:
    ParamFloatConstRange(int, int);
    char pad[12];
    int value;
    virtual void f();
};
ParamFloatConstRange::ParamFloatConstRange(int a, int b) : ParamBase(a) {
    value = b;
}