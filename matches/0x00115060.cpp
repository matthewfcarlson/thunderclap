class X {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};

bool X::Set(int x) {
    m = x;
    return true;
}
