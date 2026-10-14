class X_14c550 {
  public:
    char pad[12];
    unsigned char m;
    unsigned char Fn(unsigned char b);
};

unsigned char X_14c550::Fn(unsigned char b) {
    m = b;
    return 1;
}
