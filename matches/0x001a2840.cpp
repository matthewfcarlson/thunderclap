class X {
  public:
    char pad[0xf4];
    int mF4;
    bool Set(int);
};

bool X::Set(int v) {
    mF4 = v;
    return true;
}
