class X {
  public:
    char Set(int x);
    char pad[0x4c];
    int mValue;
};

char X::Set(int x) {
    mValue = x;
    return 1;
}
