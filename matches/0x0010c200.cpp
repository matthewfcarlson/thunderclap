class X_10c200 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};

bool X_10c200::Set(int v) {
    mValue = v;
    return true;
}
