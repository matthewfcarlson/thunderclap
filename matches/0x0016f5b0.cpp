class X {
  public:
    char pad[0x58];
    int m58;
    bool Set(int v);
};

bool X::Set(int v) {
    m58 = v;
    return true;
}
