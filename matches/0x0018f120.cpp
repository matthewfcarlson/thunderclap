class X {
  public:
    char pad[0x70];
    int m70;
    bool Set(int v);
};

bool X::Set(int v) {
    m70 = v;
    return true;
}