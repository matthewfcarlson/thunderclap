class X_1933f0 {
  public:
    char Set(int value);
    char mPad[0xa0];
    int mValue;
};

char X_1933f0::Set(int value) {
    mValue = value;
    return 1;
}
