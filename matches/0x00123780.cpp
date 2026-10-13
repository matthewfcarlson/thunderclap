class O {
  public:
    char pad[12];
    int mValue;
    char Set(int v);
};

char O::Set(int v) {
    mValue = v;
    return 1;
}
