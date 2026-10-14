class X_16edb0 {
  public:
    char Set(int value);
    char pad[0x48];
    int m48;
};

char X_16edb0::Set(int value) {
    m48 = value;
    return 1;
}
