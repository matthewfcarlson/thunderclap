class ParamValueName_13c260 {
  public:
    ParamValueName_13c260(int);
    virtual void f();
};
class ParamName : public ParamValueName_13c260 {
  public:
    ParamName(int, int);
    virtual void f();
    char pad[12];
    int value;
};
ParamName::ParamName(int a, int b) : ParamValueName_13c260(a), value(b) {}