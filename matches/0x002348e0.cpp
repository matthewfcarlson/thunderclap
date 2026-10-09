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
    *p = 0x427a38;
}