class X {
  public:
    char pad[0x16];
    char m;
    char Set(char c);
};

char X::Set(char c) {
    m = c;
    return 1;
}
