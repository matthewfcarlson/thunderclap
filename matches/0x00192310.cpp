class X_192310 {
  public:
    char pad[0x5c];
    int value;
    bool Set(int v);
};

bool X_192310::Set(int v) {
    value = v;
    return true;
}
