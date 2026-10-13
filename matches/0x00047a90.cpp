class X {
  public:
    char pad[12];
    int mVal;
    char Set(int v);
};

char X::Set(int v) {
    mVal = v;
    return 1;
}
