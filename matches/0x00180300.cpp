class X {
  public:
    int pad[3];
    int mVal;
    bool Set(int v);
};
bool X::Set(int v) {
    mVal = v;
    return true;
}