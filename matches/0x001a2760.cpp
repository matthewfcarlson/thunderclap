class C {
  public:
    char pad[0xd8];
    unsigned char mFlag;
    unsigned char SetFlag(unsigned char b);
};

unsigned char C::SetFlag(unsigned char b) {
    mFlag = b;
    return 1;
}