class X_18f060 {
  public:
    char pad[0x58];
    int m58;
    bool Set(int v);
};

bool X_18f060::Set(int v) {
    m58 = v;
    return true;
}
