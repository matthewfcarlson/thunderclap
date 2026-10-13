class Obj {
  public:
    char pad[0x24];
    char m24;
    unsigned char Set(unsigned char x);
};

unsigned char Obj::Set(unsigned char x) {
    m24 = x;
    return 1;
}
