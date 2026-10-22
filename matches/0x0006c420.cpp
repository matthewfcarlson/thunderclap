class ParamValueInt_6c420 {
  public:
    ParamValueInt_6c420(int a);
    virtual ~ParamValueInt_6c420();
};

class ParamIntConstRange_6c420 : public ParamValueInt_6c420 {
  public:
    ParamIntConstRange_6c420(int a, int b);
    virtual ~ParamIntConstRange_6c420();
    char pad[12];
    int mValue;
};

ParamIntConstRange_6c420::ParamIntConstRange_6c420(int a, int b) : ParamValueInt_6c420(a) {
    mValue = b;
}
