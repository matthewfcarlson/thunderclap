class X_47d80 {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool X_47d80::Set(int v) {
    m = v;
    return true;
}
