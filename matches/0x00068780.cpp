class X {
  public:
    char Set(int value);
    char mPad[0x10];
    int mValue;
};

char X::Set(int value) {
    mValue = value;
    return 1;
}
