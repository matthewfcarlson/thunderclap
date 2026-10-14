class X {
  public:
    char Set(char c);
    char pad[0x40];
    char m40;
};
char X::Set(char c) {
    m40 = c;
    return 1;
}
