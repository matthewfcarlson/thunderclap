class X_15ac30 {
  public:
    char pad[0x34];
    int value;
    bool Set(int v);
};
bool X_15ac30::Set(int v) {
    value = v;
    return true;
}