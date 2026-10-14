class Obj_1a26e0 {
  public:
    char pad[0xc8];
    unsigned char mFlag;
    unsigned char SetFlag(unsigned char v);
};
unsigned char Obj_1a26e0::SetFlag(unsigned char v) {
    mFlag = v;
    return 1;
}
