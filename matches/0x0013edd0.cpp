class X_13edd0 {
  public:
    char pad[0x2c];
    int mValue;
    bool Set(int v);
};

bool X_13edd0::Set(int v) {
    mValue = v;
    return true;
}
