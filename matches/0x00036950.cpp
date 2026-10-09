class A {
    char pad[0x1d78];
    unsigned char a;
    unsigned char b;

  public:
    unsigned char f(int x);
};
unsigned char A::f(int x) {
    if (a)
        return 0;
    return b;
}