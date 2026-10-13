class A {
  public:
    char f(int x);
};
char A::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
