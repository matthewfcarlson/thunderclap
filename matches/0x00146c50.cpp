class A {
  public:
    char f(int x);
    char pad[0x1c];
    int mVal;
};
char A::f(int x) {
    mVal = x;
    return 1;
}