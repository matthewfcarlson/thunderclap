class X_146d20 {
  public:
    char pad[0x24];
    int m24;
    bool Set(int v);
};
bool X_146d20::Set(int v) {
    m24 = v;
    return true;
}