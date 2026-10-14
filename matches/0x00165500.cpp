class X {
  public:
    char pad[0x34];
    char m34;
    char Set(char v);
};
char X::Set(char v) {
    m34 = v;
    return 1;
}
