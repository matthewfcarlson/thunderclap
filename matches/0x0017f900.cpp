class X_17f900 {
  public:
    char pad[0xc];
    int mValue;
    char Set(int v);
};

char X_17f900::Set(int v) {
    mValue = v;
    return 1;
}
