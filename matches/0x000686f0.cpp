class A {
  public:
    char pad[0x80];
    int m80;
    bool Set(int x);
};

bool A::Set(int x) {
    m80 = x;
    return true;
}
