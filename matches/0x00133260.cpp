class X {
  public:
    char Set(int value);

  private:
    char mPad[0x1c];
    int mValue;
};

char X::Set(int value) {
    mValue = value;
    return 1;
}
