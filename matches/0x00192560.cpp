class C {
  public:
    char mPad[0xbc];
    int mField;
    bool Set(int value);
};

bool C::Set(int value) {
    mField = value;
    return true;
}
