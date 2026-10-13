class Obj {
  public:
    char m[0x11];
    unsigned char FUN_00115040(char v);
};

unsigned char Obj::FUN_00115040(char v) {
    m[0x11] = v;
    return 1;
}
