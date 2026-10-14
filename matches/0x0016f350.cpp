class X_16f350 {
  public:
    char Set(char c);
    char pad[0x40];
    char m40;
};
char X_16f350::Set(char c) {
    m40 = c;
    return 1;
}
