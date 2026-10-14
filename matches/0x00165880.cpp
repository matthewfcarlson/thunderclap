class A {
  public:
    char pad[0x34];
    char m34;
    char Fn(char x);
};
char A::Fn(char x) {
    m34 = x;
    return 1;
}
