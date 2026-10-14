class X_16f010 {
  public:
    char Set(int x);
    char pad[0x4c];
    int mValue;
};

char X_16f010::Set(int x) {
    mValue = x;
    return 1;
}
