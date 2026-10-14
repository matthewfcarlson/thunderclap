class X_15b370 {
  public:
    char pad[0x14];
    int m;
    bool Set(int v);
};
bool X_15b370::Set(int v) {
    m = v;
    return true;
}
