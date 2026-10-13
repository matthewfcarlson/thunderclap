class A {
  public:
    char pad[0x2c];
    int value;
    bool Set(int x);
};
bool A::Set(int x) {
    value = x;
    return true;
}
