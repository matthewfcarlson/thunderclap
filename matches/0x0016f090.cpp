class X {
  public:
    char pad[0xc];
    int mX;
    bool Set(int x);
};

bool X::Set(int x) {
    mX = x;
    return true;
}
