class X_16f5b0 {
  public:
    char pad[0x58];
    int m58;
    bool Set(int v);
};

bool X_16f5b0::Set(int v) {
    m58 = v;
    return true;
}
