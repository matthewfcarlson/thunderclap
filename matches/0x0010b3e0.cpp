class A {
  public:
    char Fn(int x);
    char m[0x10];
};
char A::Fn(int x) {
    *((int*)m + 4) = x;
    return 1;
}
