class C_17fb80 {
  public:
    char pad[0x58];
    int mVal;
    bool Set(int x);
};
bool C_17fb80::Set(int x) {
    mVal = x;
    return true;
}
