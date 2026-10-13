class O {
  public:
    char pad[0x2c];
    int mVal;
    char Set(int v);
};
char O::Set(int v) {
    mVal = v;
    return 1;
}
