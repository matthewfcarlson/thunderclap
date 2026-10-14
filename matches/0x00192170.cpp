class X {
  public:
    char mPad[12];
    int mField;
    char Fn(int a);
};

char X::Fn(int a) {
    mField = a;
    return 1;
}
