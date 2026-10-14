class X {
  public:
    char pad[0xc];
    unsigned char value;
    unsigned char Fn(unsigned char a);
};

unsigned char X::Fn(unsigned char a) {
    value = a;
    return 1;
}