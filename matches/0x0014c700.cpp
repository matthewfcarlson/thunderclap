class A {
  public:
    char pad[24];
    unsigned char m18;
    unsigned char Fn(unsigned char c);
};

unsigned char A::Fn(unsigned char c) {
    m18 = c;
    return 1;
}
