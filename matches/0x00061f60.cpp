class A {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool A::Set(int v) {
    m = v;
    return true;
}