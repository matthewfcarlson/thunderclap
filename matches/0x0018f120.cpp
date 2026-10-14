class X_18f120 {
  public:
    char pad[0x70];
    int m70;
    bool Set(int v);
};

bool X_18f120::Set(int v) {
    m70 = v;
    return true;
}