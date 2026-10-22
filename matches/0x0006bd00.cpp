class ParamValueFloat_6bd00 {
  public:
    virtual void V0();
    ParamValueFloat_6bd00(int a);
};

class ParamFloatConstRange_6bd00 : public ParamValueFloat_6bd00 {
  public:
    virtual void V1();
    char pad[0x0c];
    int mValue;
    ParamFloatConstRange_6bd00(int a, int b);
};

ParamFloatConstRange_6bd00::ParamFloatConstRange_6bd00(int a, int b) : ParamValueFloat_6bd00(a) {
    mValue = b;
}
