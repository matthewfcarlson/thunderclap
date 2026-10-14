class A {
  public:
    char pad[0x18];
    int mVal;
    bool Fn(int x);
};
bool A::Fn(int x) {
    mVal = x;
    return true;
}
