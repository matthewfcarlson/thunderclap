class X {
  public:
    char pad[0xfe];
    char m0fe;
    char Set(char b);
};

char X::Set(char b) {
    m0fe = b;
    return 1;
}
