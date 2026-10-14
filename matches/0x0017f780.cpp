class X {
  public:
    char m[0x11];
    bool Set(char c);
};

bool X::Set(char c) {
    m[0x10] = c;
    return true;
}
