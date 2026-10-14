class O {
  public:
    char Set(int x);
    char pad[12];
    int mField;
};

char O::Set(int x) {
    mField = x;
    return 1;
}
