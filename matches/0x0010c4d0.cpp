class A {
  public:
    char Fn(int x);
};
char A::Fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}