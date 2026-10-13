class X {
  public:
    char pad[12];
    int mField;
    char Set(int v);
};

char X::Set(int v) {
    mField = v;
    return 1;
}
