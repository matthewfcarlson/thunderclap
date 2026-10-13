class A {
  public:
    char pad[0x30];
    int m30;
    bool Set(int v);
};

bool A::Set(int v) {
    m30 = v;
    return true;
}
