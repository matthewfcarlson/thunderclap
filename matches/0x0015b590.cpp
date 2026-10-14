class X_15b590 {
  public:
    char pad[0x20];
    int m20;
    bool Set(int v);
};

bool X_15b590::Set(int v) {
    m20 = v;
    return true;
}
