class C_192b60 {
  public:
    char SetFlag(int v);
    char mPad[0xa8];
    int mValue;
};

char C_192b60::SetFlag(int v) {
    mValue = v;
    return 1;
}
