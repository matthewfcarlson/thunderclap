class X_10c470 {
  public:
    char pad[0x18];
    int m18;
    bool Set(int v);
};

bool X_10c470::Set(int v) {
    m18 = v;
    return true;
}
