class X_68040 {
  public:
    char pad[0x24];
    int mField;
    char Set(int x);
};

char X_68040::Set(int x) {
    mField = x;
    return 1;
}
