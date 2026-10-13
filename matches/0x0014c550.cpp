class X {
  public:
    char pad[12];
    unsigned char m;
    unsigned char Fn(unsigned char b);
};

unsigned char X::Fn(unsigned char b) {
    m = b;
    return 1;
}
