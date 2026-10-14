class Obj {
  public:
    char pad[0x18];
    unsigned char m18;
    unsigned char Set(unsigned char b);
};

unsigned char Obj::Set(unsigned char b) {
    m18 = b;
    return 1;
}
