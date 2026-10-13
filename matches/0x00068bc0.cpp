class X {
  public:
    bool Set(int a);
    char mPad[12];
    int mValue;
    bool mFlag;
};

bool X::Set(int a) {
    mValue = a;
    return true;
}
