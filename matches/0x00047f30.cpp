class X_47f30 {
  public:
    char pad[12];
    int mField;
    char Set(int v);
};

char X_47f30::Set(int v) {
    mField = v;
    return 1;
}
