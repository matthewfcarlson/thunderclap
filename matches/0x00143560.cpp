class C_143560 {
  public:
    char Set(int v);
    char pad[0x40];
    int mVal;
};

char C_143560::Set(int v) {
    mVal = v;
    return 1;
}
