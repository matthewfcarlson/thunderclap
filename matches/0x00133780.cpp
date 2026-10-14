class X_133780 {
  public:
    char pad[0x2c];
    int mVal;
    bool Set(int v);
};

bool X_133780::Set(int v) {
    mVal = v;
    return true;
}
