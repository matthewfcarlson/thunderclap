class X {
  public:
    char pad[0x5c];
    int mVal;
    char Set(int v);
};

char X::Set(int v) {
    mVal = v;
    return 1;
}
