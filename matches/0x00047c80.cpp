class A {
  public:
    char pad[0xc];
    int m;
    bool Fn(int x);
};
bool A::Fn(int x) {
    m = x;
    return true;
}