class Obj {
  public:
    char pad[0x20];
    char m20;
    unsigned char Set(unsigned char v);
};

unsigned char Obj::Set(unsigned char v) {
    m20 = (char)v;
    return 1;
}
