class X_14cd80 {
  public:
    char pad[0x18];
    int value;
    bool Set(int v);
};

bool X_14cd80::Set(int v) {
    value = v;
    return true;
}
