class Obj {
  public:
    char pad[0x50];
    unsigned char mFlag;
    unsigned char FUN_00069750(unsigned char v);
};

unsigned char Obj::FUN_00069750(unsigned char v) {
    unsigned char r = 1;
    mFlag = v;
    return r;
}