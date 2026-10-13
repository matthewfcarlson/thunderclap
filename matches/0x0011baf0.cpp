class X {
  public:
    char pad[0x14];
    int m14;
    bool Set(int v);
};

bool X::Set(int v) {
    m14 = v;
    return true;
}
