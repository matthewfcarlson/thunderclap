class ParamValueInt_5bcf0 {
  public:
    virtual ~ParamValueInt_5bcf0();
    ParamValueInt_5bcf0(int a);
};
class ParamIntConstRange_5bcf0 : public ParamValueInt_5bcf0 {
  public:
    char pad[12];
    int mVal;
    ParamIntConstRange_5bcf0(int a, int b);
};
ParamIntConstRange_5bcf0::ParamIntConstRange_5bcf0(int a, int b) : ParamValueInt_5bcf0(a) {
    mVal = b;
}
