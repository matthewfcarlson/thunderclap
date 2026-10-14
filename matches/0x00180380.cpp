class X_180380 {
  public:
    char pad[0x14];
    char m;
    char Set(char c);
};

char X_180380::Set(char c) {
    m = c;
    return 1;
}
