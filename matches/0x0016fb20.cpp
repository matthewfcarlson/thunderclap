class A {
  public:
    char pad[0x20];
    int a;
    int b;
    int c;
    bool Set(int* x);
};
bool A::Set(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}
