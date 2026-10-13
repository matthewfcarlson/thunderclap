class A {
  public:
    char pad[0xc];
    unsigned char value;
    bool Set(unsigned char x);
};
bool A::Set(unsigned char x) {
    value = x;
    return true;
}
