class X {
  public:
    char pad[0xe];
    bool Set(char c);
};

bool X::Set(char c) {
    pad[0xe] = c;
    return true;
}
