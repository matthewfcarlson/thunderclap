class X_165960 {
  public:
    char pad[0xc];
    unsigned char value;
    unsigned char Fn(unsigned char a);
};

unsigned char X_165960::Fn(unsigned char a) {
    value = a;
    return 1;
}