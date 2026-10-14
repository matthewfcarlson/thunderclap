class X_16f050 {
  public:
    char Set(char b);
    char pad[0x54];
    char m54;
};

char X_16f050::Set(char b) {
    m54 = b;
    return 1;
}
