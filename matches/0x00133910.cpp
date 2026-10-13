class X {
  public:
    bool Set(int v);
    char pad[0x34];
    int m34;
};

bool X::Set(int v) {
    m34 = v;
    return true;
}
