class O {
  public:
    char pad[0x3c];
    char m3c;
    unsigned char Fn(unsigned char c);
};
unsigned char O::Fn(unsigned char c) {
    m3c = c;
    return 1;
}
