class A {
  public:
    char pad[4];
    int x;
    void f();
    int g(int, int);
};
int A::g(int a, int b) {
    if (!x)
        return -1;
    f();
    return 0;
}