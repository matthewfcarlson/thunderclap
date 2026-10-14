class X_13e840 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};
bool X_13e840::Set(int v) {
    mValue = v;
    return true;
}
