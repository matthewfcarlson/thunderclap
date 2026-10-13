class Obj {
  public:
    char pad[0x14];
    unsigned char m14;
    unsigned char Set(unsigned char v);
};

unsigned char Obj::Set(unsigned char v) {
    m14 = v;
    return 1;
}
