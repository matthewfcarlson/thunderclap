class X_603e0 {
  public:
    char Set(int v);
    char mPad[0xc0];
    int mVal;
};

char X_603e0::Set(int v) {
    mVal = v;
    return 1;
}
