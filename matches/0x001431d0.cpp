class X_1431d0 {
  public:
    char pad0[0x20];
    int value;
    char Set(int v);
};

char X_1431d0::Set(int v) {
    value = v;
    return 1;
}
