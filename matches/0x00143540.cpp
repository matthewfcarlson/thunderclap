class A {
  public:
    char pad[0x3c];
    int m3c;
    bool Set(int v);
};
bool A::Set(int v) {
    m3c = v;
    return true;
}
