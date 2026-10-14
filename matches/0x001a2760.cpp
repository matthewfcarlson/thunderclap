class C_1a2760 {
  public:
    char pad[0xd8];
    unsigned char mFlag;
    unsigned char SetFlag(unsigned char b);
};

unsigned char C_1a2760::SetFlag(unsigned char b) {
    mFlag = b;
    return 1;
}