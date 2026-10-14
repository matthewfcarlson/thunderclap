class Obj_61d80 {
  public:
    char pad[0x28];
    char mFlag;
    unsigned char SetFlag(unsigned char b);
};
unsigned char Obj_61d80::SetFlag(unsigned char b) {
    mFlag = b;
    return 1;
}
