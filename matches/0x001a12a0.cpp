class X_1a12a0 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int v);
};

char X_1a12a0::Set(int v) {
    mValue = v;
    return 1;
}
