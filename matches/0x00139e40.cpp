class X_139e40 {
  public:
    char pad[0x3c];
    int mVal;
    bool Set(int v);
};

bool X_139e40::Set(int v) {
    mVal = v;
    return true;
}
