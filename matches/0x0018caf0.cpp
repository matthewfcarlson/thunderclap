class X {
  public:
    char pad[0x18];
    char m18;
    char Set(char c);
};

char X::Set(char c) {
    m18 = c;
    return 1;
}
