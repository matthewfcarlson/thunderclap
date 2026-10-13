class X {
  public:
    char pad[0x28];
    char m;
    bool Set(char c);
};

bool X::Set(char c) {
    m = c;
    return true;
}
