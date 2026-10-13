class Obj {
  public:
    char pad[0x50];
    char m50;
    unsigned char Set(unsigned char x);
};

unsigned char Obj::Set(unsigned char x) {
    m50 = x;
    return 1;
}
