class A {
  public:
    virtual void V();
    char pad[101];
    char m69;
    char Fn(char x);
};
char A::Fn(char x) {
    m69 = x;
    return 1;
}
