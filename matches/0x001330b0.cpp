class A {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};
bool A::Set(int v) {
    mValue = v;
    return true;
}
