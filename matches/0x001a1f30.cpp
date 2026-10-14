class X {
  public:
    char m[0x10];
    int value;
    bool Set(int x);
};

bool X::Set(int x) {
    value = x;
    return true;
}
