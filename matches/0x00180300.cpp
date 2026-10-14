class X_180300 {
  public:
    int pad[3];
    int mVal;
    bool Set(int v);
};
bool X_180300::Set(int v) {
    mVal = v;
    return true;
}