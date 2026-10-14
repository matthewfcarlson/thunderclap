class X_682c0 {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int v);
};
bool X_682c0::Set(int v) {
    mValue = v;
    return true;
}