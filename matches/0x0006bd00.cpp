class Base {
  public:
    virtual void V0();
    Base(int a);
};

class ParamFloatConstRange_6bd00 : public Base {
  public:
    virtual void V1();
    char pad[0x0c];
    int mValue;
    ParamFloatConstRange_6bd00(int a, int b);
};

ParamFloatConstRange_6bd00::ParamFloatConstRange_6bd00(int a, int b) : Base(a) {
    mValue = b;
}
