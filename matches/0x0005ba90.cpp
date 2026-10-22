class ParamValueInt_5ba90 {
  public:
    ParamValueInt_5ba90(int a);
    virtual void V0();
    char pad[0xc];
};
class ParamIntConstRange_5ba90 : public ParamValueInt_5ba90 {
  public:
    ParamIntConstRange_5ba90(int a, int b);
    virtual void V0();
    int m10;
};
ParamIntConstRange_5ba90::ParamIntConstRange_5ba90(int a, int b) : ParamValueInt_5ba90(a), m10(b) {}
