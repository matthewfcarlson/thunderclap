class X_16f260 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int v);
};

char X_16f260::Set(int v) {
    mValue = v;
    return 1;
}
