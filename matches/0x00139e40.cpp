class X {
  public:
    char pad[0x3c];
    int mVal;
    bool Set(int v);
};

bool X::Set(int v) {
    mVal = v;
    return true;
}
