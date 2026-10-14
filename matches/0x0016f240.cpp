class X_16f240 {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};
bool X_16f240::Set(int v) {
    mVal = v;
    return true;
}