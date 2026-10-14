class A {
  public:
    char pad[0xa4];
    int value;
    bool Set(int v);
};

bool A::Set(int v) {
    value = v;
    return true;
}
