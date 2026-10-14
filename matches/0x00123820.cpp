class X_123820 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool X_123820::Set(int v) {
    mValue = v;
    return true;
}
