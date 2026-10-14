class Helper {
  public:
    int Go();
};
class Base {
  public:
    virtual void V0();
    virtual void V1();
    Helper* mVal;
    int Fn(int a, int b);
};
int Base::Fn(int a, int b) {
    if (!mVal)
        return -1;
    mVal->Go();
    return 0;
}
