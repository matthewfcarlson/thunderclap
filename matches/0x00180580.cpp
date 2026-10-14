class X_180580 {
  public:
    char Set(int v);
    char pad[12];
    int mField;
};

char X_180580::Set(int v) {
    mField = v;
    return true;
}
