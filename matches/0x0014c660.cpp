class X {
  public:
    char Pad[0x10];
    int mVal;
    char Set(int v);
};

char X::Set(int v) {
    mVal = v;
    return 1;
}
