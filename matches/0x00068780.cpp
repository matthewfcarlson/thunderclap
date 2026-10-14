class X_68780 {
  public:
    char Set(int value);
    char mPad[0x10];
    int mValue;
};

char X_68780::Set(int value) {
    mValue = value;
    return 1;
}
