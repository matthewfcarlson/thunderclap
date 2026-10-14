class X {
  public:
    char Set(int value);
    char mPad[0xa0];
    int mValue;
};

char X::Set(int value) {
    mValue = value;
    return 1;
}
