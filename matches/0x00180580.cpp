class X {
  public:
    char Set(int v);
    char pad[12];
    int mField;
};

char X::Set(int v) {
    mField = v;
    return true;
}
