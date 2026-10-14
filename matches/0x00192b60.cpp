class C {
  public:
    char SetFlag(int v);
    char mPad[0xa8];
    int mValue;
};

char C::SetFlag(int v) {
    mValue = v;
    return 1;
}
