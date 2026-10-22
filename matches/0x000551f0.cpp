class ParamValueNameList_551f0 {
  public:
    ParamValueNameList_551f0(int arg);
    virtual void f();
};

class ParamNameConstList : public ParamValueNameList_551f0 {
  public:
    ParamNameConstList(int a, int b);
    virtual void f();
    char pad[12];
    int m10;
};

ParamNameConstList::ParamNameConstList(int a, int b) : ParamValueNameList_551f0(a) {
    m10 = b;
}
