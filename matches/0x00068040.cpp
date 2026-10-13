class X {
  public:
    char pad[0x24];
    int mField;
    char Set(int x);
};

char X::Set(int x) {
    mField = x;
    return 1;
}
