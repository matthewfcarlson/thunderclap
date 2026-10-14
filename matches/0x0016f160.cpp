class A {
  public:
    char f(int x);
    char pad[0xc];
};
char A::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
