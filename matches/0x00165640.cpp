class X_165640 {
  public:
    char Set(int v);
    char mPad[0x28];
    int mVal;
};

char X_165640::Set(int v) {
    mVal = v;
    return 1;
}
