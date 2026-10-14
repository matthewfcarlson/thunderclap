class X_16f090 {
  public:
    char pad[0xc];
    int mX;
    bool Set(int x);
};

bool X_16f090::Set(int x) {
    mX = x;
    return true;
}
