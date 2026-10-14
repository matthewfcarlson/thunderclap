class X_18efe0 {
  public:
    char pad[0x4c];
    int value;
    char Set(int x);
};

char X_18efe0::Set(int x) {
    value = x;
    return 1;
}
