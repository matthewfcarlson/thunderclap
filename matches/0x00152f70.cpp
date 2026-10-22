class ParamValueBool_152f70 {
  public:
    ParamValueBool_152f70(float f);
    virtual void V0();
    char pad[0xc];
};
class ParamBool_152f70 : public ParamValueBool_152f70 {
  public:
    ParamBool_152f70(float f, int x);
    virtual void V0();
    int m10;
};
ParamBool_152f70::ParamBool_152f70(float f, int x) : ParamValueBool_152f70(f) {
    m10 = x;
}
