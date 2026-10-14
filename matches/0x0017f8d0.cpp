class X {
  public:
    char m[0x14];
    int mVal;
    char Set(int v);
};

char X::Set(int v) {
    mVal = v;
    return 1;
}
