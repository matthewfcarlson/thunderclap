class X_16f590 {
  public:
    char pad[0x54];
    int m;
    bool Set(int v);
};
bool X_16f590::Set(int v) {
    m = v;
    return true;
}
