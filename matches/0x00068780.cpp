class X_68780 {
  public:
    char SetTimeEnd_00068780(int value);
    char mPad[0x10];
    int mValue;
};

char X_68780::SetTimeEnd_00068780(int value) {
    mValue = value;
    return 1;
}
