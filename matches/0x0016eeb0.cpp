class X_16eeb0 {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};

bool X_16eeb0::Set(int v) {
    mVal = v;
    return true;
}