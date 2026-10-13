class A {
  public:
    char Set(int x);
    char mPad[12];
    int mVal;
};
char A::Set(int x) {
    mVal = x;
    return 1;
}