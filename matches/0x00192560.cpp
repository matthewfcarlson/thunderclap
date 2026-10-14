class C_192560 {
  public:
    char mPad[0xbc];
    int mField;
    bool Set(int value);
};

bool C_192560::Set(int value) {
    mField = value;
    return true;
}
