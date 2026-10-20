class Base {
  public:
    Base(int a);
    virtual ~Base();
};

class ParamIntConstRange_6c420 : public Base {
  public:
    ParamIntConstRange_6c420(int a, int b);
    virtual ~ParamIntConstRange_6c420();
    char pad[12];
    int mValue;
};

ParamIntConstRange_6c420::ParamIntConstRange_6c420(int a, int b) : Base(a) {
    mValue = b;
}
