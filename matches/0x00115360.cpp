class X_115360 {
  public:
    char pad[0x28];
    char m;
    bool Set(char c);
};

bool X_115360::Set(char c) {
    m = c;
    return true;
}
