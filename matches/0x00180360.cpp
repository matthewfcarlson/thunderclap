class X_180360 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool X_180360::Set(int v) {
    value = v;
    return true;
}
