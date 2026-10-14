class Obj {
  public:
    char pad[0xc8];
    unsigned char mFlag;
    unsigned char SetFlag(unsigned char v);
};
unsigned char Obj::SetFlag(unsigned char v) {
    mFlag = v;
    return 1;
}
