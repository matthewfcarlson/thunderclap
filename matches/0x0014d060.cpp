class X {
  public:
    char pad[0x24];
    int value;
    bool Set(int x);
};

bool X::Set(int x) {
    value = x;
    return true;
}
