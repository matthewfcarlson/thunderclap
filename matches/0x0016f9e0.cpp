class X_16f9e0 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};

bool X_16f9e0::Set(int v) {
    mValue = v;
    return true;
}
