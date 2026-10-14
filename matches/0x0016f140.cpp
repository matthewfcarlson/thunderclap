class X_16f140 {
  public:
    char pad[0x25];
    char m;
    bool Set(char c);
};

bool X_16f140::Set(char c) {
    m = c;
    return true;
}
