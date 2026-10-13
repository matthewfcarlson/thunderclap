class X {
  public:
    char pad[0x18];
    int m18;
    bool Set(int v);
};

bool X::Set(int v) {
    m18 = v;
    return true;
}
