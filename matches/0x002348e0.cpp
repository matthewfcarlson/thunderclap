extern "C" char DAT_00427a38[];
class ParamValue {
  public:
    ParamValue(int);
    virtual void F();
};
class ParamValueInt {
  public:
    virtual void F();
    char pad[4];
    ParamValue value;
    ParamValueInt(int);
};
ParamValueInt::ParamValueInt(int x) : value(x) {
    volatile int* p = (volatile int*)this;
    *p = ((int)DAT_00427a38);
}