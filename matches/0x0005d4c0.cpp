class X_5d4c0 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int x);
};
char X_5d4c0::Set(int x) {
    mValue = x;
    return 1;
}
