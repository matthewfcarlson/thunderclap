class O_123780 {
  public:
    char pad[12];
    int mValue;
    char Set(int v);
};

char O_123780::Set(int v) {
    mValue = v;
    return 1;
}
