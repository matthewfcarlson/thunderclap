class X_13e810 {
  public:
    char pad[0xc];
    int m12;
    bool Set(int v);
};

bool X_13e810::Set(int v) {
    m12 = v;
    return true;
}
