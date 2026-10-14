class O_61f20 {
  public:
    char pad[0x3c];
    char m3c;
    unsigned char Fn(unsigned char c);
};
unsigned char O_61f20::Fn(unsigned char c) {
    m3c = c;
    return 1;
}
