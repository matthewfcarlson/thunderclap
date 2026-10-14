class X_192160 {
  public:
    char pad[12];
    char m;
    char Set(char c);
};

char X_192160::Set(char c) {
    m = c;
    return 1;
}
