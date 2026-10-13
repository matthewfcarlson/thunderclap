class A {
  public:
    char pad[0x24];
    int mField;
    bool Set(int x);
};

bool A::Set(int x) {
    mField = x;
    return true;
}
