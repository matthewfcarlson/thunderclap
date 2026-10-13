class X {
  public:
    char pad[0x10];
    int mValue;
    char Set(int x);
};
char X::Set(int x) {
    mValue = x;
    return 1;
}
