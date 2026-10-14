class X_165510 {
  public:
    char pad[12];
    int mValue;
    char Set(int v);
};

char X_165510::Set(int v) {
    mValue = v;
    return 1;
}