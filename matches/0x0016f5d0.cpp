class X_16f5d0 {
  public:
    char pad[0x5c];
    int mVal;
    char Set(int v);
};

char X_16f5d0::Set(int v) {
    mVal = v;
    return 1;
}
