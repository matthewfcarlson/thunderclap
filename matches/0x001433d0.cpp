class X {
  public:
    char pad[0x38];
    int m38;
    bool Set(int v);
};
bool X::Set(int v) {
    m38 = v;
    return true;
}
