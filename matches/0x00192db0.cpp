class X_192db0 {
  public:
    char pad[0xfe];
    char m0fe;
    char Set(char b);
};

char X_192db0::Set(char b) {
    m0fe = b;
    return 1;
}
