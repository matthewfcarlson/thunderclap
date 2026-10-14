class X_682b0 {
  public:
    char pad[0x1c];
    int mVal;
    bool Set(int v);
};
bool X_682b0::Set(int v) {
    mVal = v;
    return true;
}