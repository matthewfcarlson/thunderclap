class X {
  public:
    char m[0xa9];
    char f;
    bool Set(char c);
};

bool X::Set(char c) {
    f = c;
    return true;
}
