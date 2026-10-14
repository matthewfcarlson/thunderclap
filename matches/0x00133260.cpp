class X_133260 {
  public:
    char Set(int value);

  private:
    char mPad[0x1c];
    int mValue;
};

char X_133260::Set(int value) {
    mValue = value;
    return 1;
}
