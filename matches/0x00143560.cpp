class C {
  public:
    char Set(int v);
    char pad[0x40];
    int mVal;
};

char C::Set(int v) {
    mVal = v;
    return 1;
}
