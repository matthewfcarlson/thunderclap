class X {
  public:
    char Set(int v);
    char mPad[0x28];
    int mVal;
};

char X::Set(int v) {
    mVal = v;
    return 1;
}
