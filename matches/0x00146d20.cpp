class X {
  public:
    char pad[0x24];
    int m24;
    bool Set(int v);
};
bool X::Set(int v) {
    m24 = v;
    return true;
}