class Obj {
  public:
    char pad[0x28];
    char mFlag;
    unsigned char SetFlag(unsigned char b);
};
unsigned char Obj::SetFlag(unsigned char b) {
    mFlag = b;
    return 1;
}
