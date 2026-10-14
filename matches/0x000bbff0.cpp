class Helper_bbff0 {
  public:
    int Go();
};
class Base_bbff0 {
  public:
    virtual void V0();
    virtual void V1();
    Helper_bbff0* mVal;
    int Fn(int a, int b);
};
int Base_bbff0::Fn(int a, int b) {
    if (!mVal)
        return -1;
    mVal->Go();
    return 0;
}
