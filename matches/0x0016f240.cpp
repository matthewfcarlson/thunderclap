class X {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};
bool X::Set(int v) {
    mVal = v;
    return true;
}