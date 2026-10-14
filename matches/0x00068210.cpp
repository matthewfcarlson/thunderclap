class O_68210 {
  public:
    char pad[0x58];
    unsigned char m58;
    char Set(unsigned char x);
};

char O_68210::Set(unsigned char x) {
    m58 = x;
    return 1;
}
